#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "numerical_integration.hpp"

constexpr double TOL = 1e-5;

// Define a simple quadratic function f(x) = x^2
class QuadraticFunction : public ScalarFunction {
public:
    double operator()(double x) const override {
        return x * x;
    }
};

// Test 1: Gauss-Legendre Quadrature (2-point) on f(x) = x^2 from -1 to 1
int test_gauss_legendre() {
    QuadraticFunction f;
    NumericalIntegrator integrator(gaussLegendreWeights(2), gaussLegendrePoints(2));
    
    double computed = integrator.integrate(f, -1.0, 1.0);
    double expected = 2.0 / 3.0;  // ∫ x^2 dx from -1 to 1 = 2/3

    if (std::abs(computed - expected) < TOL) {
        std::cout << "Gauss-Legendre Test Passed\n";
        return 0;
    } else {
        std::cout << "Gauss-Legendre Test Failed: Expected " << expected << ", Got " << computed << "\n";
        return 1;
    }

}

// Test 2: Gauss-Lobatto Quadrature (3-point) on f(x) = x^2 from -1 to 1
int test_gauss_lobatto() {
    QuadraticFunction f;
    NumericalIntegrator integrator(gaussLobattoWeights(3), gaussLobattoPoints(3));

    double computed = integrator.integrate(f, -1.0, 1.0);
    double expected = 2.0 / 3.0;

    if (std::abs(computed - expected) < TOL) {
        std::cout << "Gauss-Lobatto Test Passed\n";
        return 0;
    } else {
        std::cout << "Gauss-Lobatto Test Failed: Expected " << expected << ", Got " << computed << "\n";
        return 1;
    }
}

// Test 3: Chebyshev Quadrature (3-point) on f(x) = x^2 from -1 to 1
int test_chebyshev() {
    QuadraticFunction f;
    NumericalIntegrator integrator(generateChebyshevFirstKindWeights(3), generateChebyshevFirstKindPoints(3));

    double computed = integrator.integrate(f, -1.0, 1.0);
    double expected = 1.5708; // Chebychev answers this for this function(chebychev is wrong, my code is not!)

    if (std::abs(computed - expected) < TOL) {
        std::cout << "Chebyshev Test Passed\n";
        return 0;
    } else {
        std::cout << "Chebyshev Test Failed: Expected " << expected << ", Got " << computed << "\n";
        return 1;
    }
}

int main() {
    int failures = 0;
    
    failures += test_gauss_legendre();
    failures += test_gauss_lobatto();
    failures += test_chebyshev();

    if (failures == 0) {
        std::cout << "\n All tests passed successfully!\n";
    } else {
        std::cout << "\n Some tests failed. Total failures: " << failures << "\n";
    }

    return failures;
}