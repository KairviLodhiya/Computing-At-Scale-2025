
#ifndef READWRITEMMFILES_H
#define READWRITEMMFILES_H

#include <vector>
#include <stdexcept>
#include <fstream>

void readMatrixMarketFile(const std::string &filename, std::vector<std::vector<double>> &matrix);
void writeMatrixMarketFile(const std::string &filename, const std::vector<std::vector<double>> &matrix);

#endif