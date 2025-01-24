#include <iostream>
#include <vector>
#include <fstream>
#include "readwriteMMfiles.hpp"   
extern "C" {
#include "mmio.h"
}


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
