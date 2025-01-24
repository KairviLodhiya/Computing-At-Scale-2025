#include <iostream>
#include <fstream>
#include <vector>
#include "matrixMultiply.hpp"
extern "C" {
#include "mmio.h"
}
#include "readwriteMMfiles.cpp"

bool areMatricesEqual(const std::vector<std::vector<double>>& m1, 
                      const std::vector<std::vector<double>>& m2, 
                      double epsilon = 1e-9) {
    // Check if the sizes of the matrices match
    if (m1.size() != m2.size()) {
        return false; // Different number of rows
    }

    for (size_t i = 0; i < m1.size(); ++i) {
        if (m1[i].size() != m2[i].size()) {
            return false; // Different number of columns in row i
        }
        for (size_t j = 0; j < m1[i].size(); ++j) {
            if (std::abs(m1[i][j] - m2[i][j]) >= epsilon) {
                return false; // If any element differs more than epsilon
            }
        }
    }

    return true; // All elements are within the tolerance
}

bool areVectorsEqual(const std::vector<double>& v1, const std::vector<double>& v2, double epsilon = 1e-9) {
    if (v1.size() != v2.size()) {
        return false; // Vectors are not equal if their sizes differ
    }

    for (size_t i = 0; i < v1.size(); ++i) {
        if (std::abs(v1[i] - v2[i]) >= epsilon) {
            return false; // If any element differs more than epsilon, vectors are not equal
        }
    }

    return true; // All elements are within the tolerance
}


void testMatrixOperations() {
    // Read matrix and vector from Matrix Market files
    std::vector<std::vector<double>> matrix1, matrix2;
    std::vector<double> vector1;

    // Test case 1: Matrix-Vector multiplication
    readMatrixMarketFile("matrix1.mtx", matrix1);  // Read matrix1 and check if its matrix or vector
   // readMatrixMarketFile("vector1.mtx", vector1);  // Read vector1 and check if its matrix or vector

    // Perform matrix-vector multiplication
    std::vector<double> result1 = matrixVectorProduct(matrix1, vector1);

    // Expected result
    std::vector<double> expectedResult1 = {6.0, 15.0, 24.0};
    
    // Compare results
    bool passed1 = areVectorsEqual(result1, expectedResult1);
    std::cout << "Matrix-Vector Multiplication: " << (passed1 ? "PASS" : "FAIL") << std::endl;

    // Test case 2: Matrix-Matrix multiplication
    readMatrixMarketFile("matrix2.mtx", matrix2);  // Read matrix2 and check if its matrix or vector

    // Perform matrix-matrix multiplication
    std::vector<std::vector<double>> result2 = matrixMatrixProduct(matrix1, matrix2);

    // Expected result
    std::vector<std::vector<double>> expectedResult2 = {
        {30.0, 36.0, 42.0},
        {66.0, 81.0, 96.0},
        {102.0, 126.0, 150.0}
    };

    // Compare results
    bool passed2 = areMatricesEqual(result2, expectedResult2);
    std::cout << "Matrix-Matrix Multiplication: " << (passed2 ? "PASS" : "FAIL") << std::endl;
}

int main() {
    testMatrixOperations();
    return 0;
}
