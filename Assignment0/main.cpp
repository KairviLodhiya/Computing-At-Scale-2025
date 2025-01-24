#include <iostream>
#include <vector>
#include <fstream>
#include "matrixMultiply.hpp"   
#include "readwriteMMfiles.hpp"
extern "C" {
#include "mmio.h"
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
            vector.resize(vectorMatrix.size()); // Preallocate space for the vector
            for (size_t i = 0; i < vectorMatrix.size(); ++i) {
                vector[i] = vectorMatrix[i][0]; // Directly assign the value
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
