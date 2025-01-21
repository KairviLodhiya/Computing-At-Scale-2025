#include "header.hpp"

std::vector<double> matrixVectorProduct(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vec) {
    if (matrix.empty() || matrix[0].size() != vec.size()) {
        throw std::invalid_argument("The number of columns in the matrix must equal the number of elements in the vector.");
    }

    std::vector<double> result(matrix.size(), 0.0);
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < vec.size(); ++j) {
            result[i] += matrix[i][j] * vec[j];
        }
    }

    return result;
}

