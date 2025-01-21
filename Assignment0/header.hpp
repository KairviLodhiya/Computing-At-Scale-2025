
#ifndef MATRIXVECTORPRODUCT_H
#define MATRIXVECTORPRODUCT_H

#include <vector>
#include <stdexcept>

// Function declaration
std::vector<double> matrixVectorProduct(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vec);

#endif // MATRIXVECTORPRODUCT_H

#ifndef MATRIXMATRIXPRODUCT_H
#define MATRIXMATRIXPRODUCT_H

#include <vector>
#include <stdexcept>

// Function declaration
std::vector<std::vector<double>> matrixMatrixProduct(const std::vector<std::vector<double>>& mat1, const std::vector<std::vector<double>>& mat2);

#endif // MATRIXMATRIXPRODUCT_H