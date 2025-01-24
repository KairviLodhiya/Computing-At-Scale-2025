
#ifndef MATRIXMULTIPLY_H
#define MATRIXMULTIPLY_H

#include <vector>
#include <stdexcept>

// Function declaration
std::vector<double> matrixVectorProduct(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vec);
std::vector<std::vector<double>> matrixMatrixProduct(const std::vector<std::vector<double>>& mat1, const std::vector<std::vector<double>>& mat2);

#endif // MATRIXMULTIPLY_H
