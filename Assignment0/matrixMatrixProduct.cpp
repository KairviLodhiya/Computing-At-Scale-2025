#include "header.hpp"
#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<double>> matrixMatrixProduct(const std::vector<std::vector<double>>& mat1, const std::vector<std::vector<double>>& mat2) {

    size_t m = mat1.size();           // Rows in mat1
    size_t n = mat1[0].size();        // Columns in mat1 
    size_t q = mat2.size();           // Rows in mat2
    size_t p = mat2[0].size();        // Columns in mat2
    
    if (mat1.empty() || mat2.empty() || n != q) {
        throw std::invalid_argument("The number of columns in the matrix 1 must equal the number of rows in matrix 2.");
    }

    // Initialize the result matrix mat3 with zeros
    std::vector<std::vector<double>> mat3(m, std::vector<double>(p, 0.0));


    // Perform matrix multiplication
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < p; ++j) {
            for (size_t k = 0; k < n; ++k) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return mat3;
}