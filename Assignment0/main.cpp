#include <iostream>
#include <vector>
#include <fstream>
extern "C" {
#include "mmio.h"
}

// Include the function declarations
std::vector<double> matrixVectorProduct(const std::vector<std::vector<double>> &matrix, const std::vector<double> &vec);
std::vector<std::vector<double>> matrixMatrixProduct(const std::vector<std::vector<double>> &mat1, const std::vector<std::vector<double>> &mat2);

/* Reading matrix market file function */
void readMatrixMarketFile(const std::string &filename, std::vector<std::vector<double>> &matrix) {
    
    MM_typecode matcode;
    FILE *f;
    int M, N;   

    if ((f = fopen(filename.c_str(), "r")) == NULL) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    if (mm_read_banner(f, &matcode) != 0) {
        throw std::runtime_error("Could not read Matrix Market banner.");
    }

    if (!mm_is_matrix(matcode) || !mm_is_dense(matcode)) {
        throw std::runtime_error("Only dense matrices are supported.");
    }

    /*  This is how one can screen matrix types if their application */
    /*  only supports a subset of the Matrix Market data types.      */
     /* Only supports dense matrix */



    /* NOTE: when reading in doubles, ANSI C requires the use of the "l"  */
    /*   specifier as in "%lg", "%lf", "%le", otherwise errors will occur */
    /*  (ANSI C X3.159-1989, Sec. 4.9.6.2, p. 136 lines 13-15)            */

    mm_read_mtx_array_size(f, &M, &N);

    matrix.resize(M, std::vector<double>(N, 0.0));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (fscanf(f, "%lf", &matrix[i][j]) != 1) {
                throw std::runtime_error("Error reading matrix values.");
            }
        }
    }

    fclose(f);
}

/* Writing matrix market file function */
void writeMatrixMarketFile(const std::string &filename, const std::vector<std::vector<double>> &matrix) {
    FILE *f;
    int M = matrix.size();
    int N = matrix[0].size();

    if ((f = fopen(filename.c_str(), "w")) == NULL) {
        throw std::runtime_error("Could not open file for writing: " + filename);
    }

    MM_typecode matcode;
    mm_initialize_typecode(&matcode);
    mm_set_matrix(&matcode);
    mm_set_array(&matcode);
    mm_set_real(&matcode);
    mm_set_general(&matcode);

    mm_write_banner(f, matcode);
    mm_write_mtx_array_size(f, M, N);

    for (const auto &row : matrix) {
        for (double value : row) {
            fprintf(f, "%10.3g \n", value);
        }
    }

    fclose(f);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input_file1> <input_file2> <operation_type>\n";
        std::cerr << "operation_type: 0 for matrix-vector, 1 for matrix-matrix\n";
        return 1;
    }

    std::string inputFile1 = argv[1];
    std::string inputFile2 = argv[2];
    int operationType = std::stoi(argv[3]);
try {
        if (operationType == 0) {
            // Matrix-Vector Multiplication
            std::vector<std::vector<double>> matrix;
            std::vector<double> vector;

            readMatrixMarketFile(inputFile1, matrix);

            // Read vector from the second file (special case: one-column matrix)
            std::vector<std::vector<double>> vectorMatrix;
            readMatrixMarketFile(inputFile2, vectorMatrix);
            if (vectorMatrix[0].size() != 1) {
                throw std::runtime_error("The second input must be a single-column matrix (vector).");
            }
            for (const auto &row : vectorMatrix) {
                vector.push_back(row[0]);
            }

            std::vector<double> result = matrixVectorProduct(matrix, vector);

            // Convert result to a single-column matrix for output
            std::vector<std::vector<double>> resultMatrix(result.size(), std::vector<double>(1));
            for (size_t i = 0; i < result.size(); ++i) {
                resultMatrix[i][0] = result[i];
            }

            writeMatrixMarketFile("result.mtx", resultMatrix);
        } else if (operationType == 1) {
            // Matrix-Matrix Multiplication
            std::vector<std::vector<double>> matrix1, matrix2;

            readMatrixMarketFile(inputFile1, matrix1);
            readMatrixMarketFile(inputFile2, matrix2);

            std::vector<std::vector<double>> result = matrixMatrixProduct(matrix1, matrix2);

            writeMatrixMarketFile("result.mtx", result);
        } else {
            throw std::invalid_argument("Invalid operation type. Use 0 for matrix-vector or 1 for matrix-matrix.");
        }

        std::cout << "Result written to 'result.mtx' in Matrix Market format.\n";
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
