#include <iostream>
#include <fstream>
#include <vector>
#include "header.hpp"
#include "mmio.h"

void readMatrixMarketFile(const std::string &filename, std::vector<std::vector<double>> &matrix, std::vector<double> &vector) {
    MM_typecode matcode;
    FILE *f;
    int M, N;

    // Open the file
    if ((f = fopen(filename.c_str(), "r")) == NULL) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    // Read the Matrix Market banner
    if (mm_read_banner(f, &matcode) != 0) {
        throw std::runtime_error("Could not read Matrix Market banner.");
    }

    // Check if it's a matrix or a vector
    if (!mm_is_matrix(matcode) || (!mm_is_dense(matcode) && !mm_is_array(matcode))) {
        throw std::runtime_error("Only dense matrices or vectors are supported.");
    }

    // Read matrix size
    mm_read_mtx_array_size(f, &M, &N);

    // If it's a matrix
    if (M > 1 && N > 1) {
        matrix.resize(M, std::vector<double>(N, 0.0));
        // Read matrix values
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (fscanf(f, "%lf", &matrix[i][j]) != 1) {
                    throw std::runtime_error("Error reading matrix values.");
                }
            }
        }
    }
    // If it's a vector (matrix with a single row or column)
    else if (M == 1 || N == 1) {
        vector.resize(std::max(M, N), 0.0);
        // Read vector values
        for (int i = 0; i < std::max(M, N); ++i) {
            if (fscanf(f, "%lf", &vector[i]) != 1) {
                throw std::runtime_error("Error reading vector values.");
            }
        }
    }

    fclose(f);
}


void testMatrixOperations() {
    // Read matrix and vector from Matrix Market files
    std::vector<std::vector<double>> matrix1, matrix2;
    std::vector<double> vector1;

    // Test case 1: Matrix-Vector multiplication
    readMatrixMarketFile("matrix1.mtx", matrix1, vector1);  // Read matrix1 and check if its matrix or vector
    readMatrixMarketFile("vector1.mtx", matrix1, vector1);  // Read vector1 and check if its matrix or vector

    // Perform matrix-vector multiplication
    std::vector<double> result1 = matrixVectorProduct(matrix1, vector1);

    // Expected result
    std::vector<double> expectedResult1 = {6.0, 15.0, 24.0};
    
    // Compare results
    bool passed1 = (result1 == expectedResult1);
    std::cout << "Matrix-Vector Multiplication: " << (passed1 ? "PASS" : "FAIL") << std::endl;

    // Test case 2: Matrix-Matrix multiplication
    readMatrixMarketFile("matrix2.mtx", matrix2, vector1);  // Read matrix2 and check if its matrix or vector

    // Perform matrix-matrix multiplication
    std::vector<std::vector<double>> result2 = matrixMatrixProduct(matrix1, matrix2);

    // Expected result
    std::vector<std::vector<double>> expectedResult2 = {
        {30.0, 36.0, 42.0},
        {66.0, 81.0, 96.0},
        {102.0, 126.0, 150.0}
    };

    // Compare results
    bool passed2 = (result2 == expectedResult2);
    std::cout << "Matrix-Matrix Multiplication: " << (passed2 ? "PASS" : "FAIL") << std::endl;
}

int main() {
    testMatrixOperations();
    return 0;
}
