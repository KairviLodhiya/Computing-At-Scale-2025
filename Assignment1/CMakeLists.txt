cmake_minimum_required(VERSION 3.28.3)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)


# Create the integration library
add_library(integration_library numerical_integration.cpp)

project(PolynomialIntegrate CXX)
    
# Polynomial integration executable
add_executable(PolynomialIntegrate PolynomialIntegrate.cpp)
target_link_libraries(PolynomialIntegrate integration_library)

# Create the unit test executable
add_executable(unit_tests unit_tests.cpp)
target_link_libraries(unit_tests integration_library)