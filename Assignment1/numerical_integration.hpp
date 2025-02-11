
#include <vector>
#include <cmath>

// Base class
class ScalarFunction{
    public:
    virtual ~ScalarFunction() = default;
    virtual double operator()(double x) const = 0;
};

// Class for Numerical Integration
class NumericalIntegrator{
    private:
        std::vector<double> weights;
        std::vector<double> samplingLocations;

    public:
        NumericalIntegrator(const std::vector<double>& w, const std::vector<double>& x):weights(w), samplingLocations(x){}
        double integrate(const ScalarFunction& func, double a, double b) const;
        
};

// Gauss-Legendre Quadrature (1 to 4 points)
std::vector<double> gaussLegendrePoints(double n);
std::vector<double> gaussLegendreWeights(double n);

// Gauss-Lobatto Quadrature (3 to 5 points)
std::vector<double> gaussLobattoPoints(double n);
std::vector<double> gaussLobattoWeights(double n);

// Gauss-Chebyshev Quadrature (First Kind)
std::vector<double> generateChebyshevFirstKindPoints(double n);
std::vector<double> generateChebyshevFirstKindWeights(double n);


