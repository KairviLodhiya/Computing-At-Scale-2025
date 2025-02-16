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
    try {
        if (argc < 8) {
            throw std::runtime_error("Usage: " + std::string(argv[0]) + 
                " <method> <no. of points> <a> <b> <coeff1> <coeff2> .... ");
        }

        std::string method = argv[1];
        double n = std::stod(argv[2]);
        double a = std::stod(argv[3]);
        double b = std::stod(argv[4]);

        // Ensure that a is smaller than b
        if (a >= b) {
            throw std::invalid_argument("Invalid integration limits: 'a' must be smaller than 'b'.");
        }

        // Ensure no negative numbers
        if (n < 0) {
            throw std::invalid_argument("Invalid input: 'n', 'a', and 'b' must be non-negative.");
        }

        std::vector<double> coefficients;

        // Parse coefficients
        for (int i = 5; i < argc; ++i) {
            double coeff = std::stod(argv[i]);
            if (coeff < 0) {
                throw std::invalid_argument("Invalid input: Coefficients must be non-negative.");
            }
            coefficients.push_back(coeff);
        }

        PolynomialFunction poly(coefficients);
        std::vector<double> points, weights;

        // Select numerical integration method
        if (method == "gauss_legendre") {
            points = gaussLegendrePoints(n);
            weights = gaussLegendreWeights(n);
        } else if (method == "gauss_lobatto") {
            points = gaussLobattoPoints(n);
            weights = gaussLobattoWeights(n);
        } else if (method == "chebychev") {
            points = generateChebyshevFirstKindPoints(n);
            weights = generateChebyshevFirstKindWeights(n);
        } else {
            throw std::invalid_argument("Unknown integration method: " + method);
        }

        NumericalIntegrator integrator(weights, points);
        double result = integrator.integrate(poly, a, b);

        std::cout << "Integral result: " << result << "\n";
        
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "Unknown error occurred." << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}