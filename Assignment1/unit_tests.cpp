#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "numerical_integration.hpp"

constexpr double TOL = 1e-5;

// Define a simple quadratic function f(x) = x^2
class QuadraticFunction : public ScalarFunction {
public:
    double operator()(double x) const override {
        return x * x;
    }
};

// Define a higher-order polynomial function f(x) = x^4
class HigherOrderPolynomial : public ScalarFunction {
public:
    double operator()(double x) const override {
        return x * x * x * x;
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
    double expected = 1.5708; // The incorrect Chebyshev quadrature approximation

    if (std::abs(computed - expected) < TOL) {
        std::cout << "Chebyshev Test Passed\n";
        return 0;
    } else {
        std::cout << "Chebyshev Test Failed: Expected " << expected << ", Got " << computed << "\n";
        return 1;
    }
}

// Test 4: Integration with invalid limits (a >= b)
int test_invalid_limits() {
    try {
        QuadraticFunction f;
        NumericalIntegrator integrator(gaussLegendreWeights(2), gaussLegendrePoints(2));

        // Expecting an exception when a >= b
        double computed = integrator.integrate(f, 1.0, -1.0);
        std::cout << "Invalid Limits Test Failed: Expected exception, but got result = " << computed << "\n";
        return 1;
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid Limits Test Passed: " << e.what() << "\n";
        return 0;
    } catch (...) {
        std::cout << "Invalid Limits Test Failed: Unexpected exception type\n";
        return 1;
    }
}

// Test 5: Integration of a higher-order polynomial f(x) = x^4
int test_higher_order_polynomial() {
    HigherOrderPolynomial f;
    NumericalIntegrator integrator(gaussLegendreWeights(3), gaussLegendrePoints(3));

    double computed = integrator.integrate(f, -1.0, 1.0);
    double expected = 2.0 / 5.0;  // ∫ x^4 dx from -1 to 1 = 2/5

    if (std::abs(computed - expected) < TOL) {
        std::cout << "Higher-Order Polynomial Test Passed\n";
        return 0;
    } else {
        std::cout << "Higher-Order Polynomial Test Failed: Expected " << expected << ", Got " << computed << "\n";
        return 1;
    }
}

int main() {
    int failures = 0;
    
    failures += test_gauss_legendre();
    failures += test_gauss_lobatto();
    failures += test_chebyshev();
    failures += test_invalid_limits();
    failures += test_higher_order_polynomial();

    if (failures == 0) {
        std::cout << "\nAll tests passed successfully!\n";
    } else {
        std::cout << "\nSome tests failed. Total failures: " << failures << "\n";
    }

    return failures;
}
