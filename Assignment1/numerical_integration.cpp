#include "numerical_integration.hpp"
#include <cmath>
#include <iostream>

double NumericalIntegrator::integrate(const ScalarFunction& func, double a, double b) const {
    double sum = 0.0;
    for (auto i = 0; i < weights.size(); ++i) {
        double x_mapped = 0.5 * (b - a) * samplingLocations[i] + 0.5 * (a + b);
        double fx = func(x_mapped);
        double weighted_fx = weights[i] * fx;
        sum += weights[i] * func(x_mapped);
    }
    sum = sum* 0.5 * (b - a);
    return sum;
    
}

// Gauss-Legendre Quadrature Points and Weights
std::vector<double> gaussLegendrePoints(double n) {
    if (n == 1) return {0.0};
    if (n == 2) return {-0.57735026919, 0.57735026919};
    if (n == 3) return {-0.77459666924, 0.0, 0.77459666924};
    if (n == 4) return {-0.86113631159, -0.33998104358, 0.33998104358, 0.86113631159};
    if (n == 5) throw std::invalid_argument("Incorrect n value");
    return {};
}

std::vector<double> gaussLegendreWeights(double n) {
    if (n == 1) return {2.0};
    if (n == 2) return {1.0, 1.0};
    if (n == 3) return {0.55555555556, 0.88888888889, 0.55555555556};
    if (n == 4) return {0.34785484514, 0.65214515486, 0.65214515486, 0.34785484514};
    if (n == 5) throw std::invalid_argument("Incorrect n value");
    return {};
}

// Gauss-Lobatto Quadrature Points and Weights
std::vector<double> gaussLobattoPoints(double n) {
    if (n == 3) return {-1.0, 0.0, 1.0};
    if (n == 4) return {-1.0, -0.4472135955, 0.4472135955, 1.0};
    if (n == 5) return {-1.0, -0.6546536707, 0.0, 0.6546536707, 1.0};
    if (n == 6) throw std::invalid_argument("Incorrect n value");
    return {};
}

std::vector<double> gaussLobattoWeights(double n) {
    if (n == 3) return {1.0 / 3.0, 4.0 / 3.0, 1.0 / 3.0};
    if (n == 4) return {1.0 / 6.0, 5.0 / 6.0, 5.0 / 6.0, 1.0 / 6.0};
    if (n == 5) return {1.0 / 10.0, 49.0 / 90.0, 32.0 / 45.0, 49.0 / 90.0, 1.0 / 10.0};
    if (n == 6) throw std::invalid_argument("Incorrect n value");
    return {};
}

// Gauss-Chebyshev Quadrature (First Kind)
std::vector<double> generateChebyshevFirstKindPoints(double n) {
    std::vector<double> points(n);
    for (int i = 0; i < n; ++i) {
        points[i] = std::cos(M_PI * (2 * i + 1) / (2 * n));
    }
    
    return points;
}

std::vector<double> generateChebyshevFirstKindWeights(double n) {
    std::vector<double> weights(n, M_PI / n);
    return weights;
}
