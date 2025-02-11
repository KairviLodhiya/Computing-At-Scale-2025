#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "numerical_integration.hpp"

class PolynomialFunction : public ScalarFunction {
private:
    std::vector<double> coefficients;

public:
    PolynomialFunction(const std::vector<double>& coeffs) : coefficients(coeffs) {}

    double operator()(double x) const override {
        double result = 0.0;
        double power = 1.0;
        int deg = coefficients.size() - 1;
        for (int i = 0; i <= deg; ++i) {
            result += coefficients[i] * std::pow(x, deg - i);
        }
        return result;
    };
};

int main(int argc, char* argv[]) {
    if (argc < 8) {
        std::cerr<< "Usage: " << argv[0] << " <method> <no. of points> <a> <b> <coeff1> <coeff2> <coeff3>  ";
        return 1;
    }

    std::string method = argv[1];
    double n = std::stod(argv[2]);
    double a = std::stod(argv[3]);
    double b = std::stod(argv[4]);
    double c1 = std::stod(argv[5]);
    double c2 = std::stod(argv[6]);
    double c3 = std::stod(argv[7]);
    std::vector<double> coefficients = {c1, c2, c3};
    
    PolynomialFunction poly(coefficients);
    std::vector<double> points, weights;

    if (method == "gauss_legendre") {
        points = gaussLegendrePoints(n);
        weights = gaussLegendreWeights(n);
    } else if (method == "gauss_lobatto") {
        points = gaussLobattoPoints(n);
        weights = gaussLobattoWeights(n);
    } else if (method == "chebychev") {
        points = generateChebyshevFirstKindPoints(n);
        weights = generateChebyshevFirstKindWeights(n);
    }
    else {
        std::cerr << "Unknown integration method!\n";
        return 1;
    }

    NumericalIntegrator integrator(weights, points);
    double result = integrator.integrate(poly, a, b);

    std::cout << "Integral result: " << result << std::endl;
    return 0;
}