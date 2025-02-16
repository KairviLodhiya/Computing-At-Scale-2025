# Numerical Integration Library

This library implements several numerical integration methods, including **Gauss-Legendre**, **Gauss-Lobatto**, and **Gauss-Chebyshev Quadrature** (First Kind). These methods are used to estimate the definite integral of scalar functions over a specified interval.

---

## Overview

This project provides numerical methods to estimate integrals of functions using various quadrature techniques. The integration process is based on weights and sample locations that are predefined for different quadrature methods.

The library supports:
- Gauss-Legendre Quadrature for functions where high precision is needed.
- Gauss-Lobatto Quadrature for functions defined on a closed interval with endpoints included.
- Gauss-Chebyshev Quadrature (First Kind) for integrals involving weights.

The integration methods use precomputed points and weights for the respective quadrature method and apply them to the given function within the provided limits.

---

## Code files

- **numerical_integration.hpp** - It is the header file that defines the base class and all the functions.
- **numerical_integration.cpp** - It is the library of Numerical Integration methods and computes the integral.
- **PolynomialIntegrate.cpp** - This includes the method that preprocesses the input into the Polynomial function such that can be computed by the numerical integration file. 
- **unit_tests.cpp** - This is the testing file for the numerical integration library. The function tested in the file is x^2. 

## Instructions to run

1. Clone the Repository.
2. Create the build directory.
3. Run CMake to generate the build system.
4. Use make command.
5. Run the program in this format:
    ./PolynomialIntegrate <method> <num_points> <a> <b> <coeff1> <coeff2> <coeff3>
    (method - gauss_legendre, gauss_lobatto, chebychev)
6. Run the unit tests:
    ./unit_tests
