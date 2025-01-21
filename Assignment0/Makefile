# Compiler and flags
CXX = g++
CC = gcc
CXXFLAGS = -Wall -g

# Target executable
TARGET = matrix_operations

# Object files
OBJECTS = main.o matrixVectorProduct.o matrixMatrixProduct.o mmio.o

# Default target: compile and link the program
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Compile the main driver
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile matrixVectorProduct
matrixVectorProduct.o: matrixVectorProduct.cpp
	$(CXX) $(CXXFLAGS) -c matrixVectorProduct.cpp

# Compile matrixMatrixProduct
matrixMatrixProduct.o: matrixMatrixProduct.cpp
	$(CXX) $(CXXFLAGS) -c matrixMatrixProduct.cpp

# Compile mmio
mmio.o: mmio.c
	$(CC) -c mmio.c

# Clean the build
clean:
	rm $(TARGET) $(OBJECTS)

# Run the program with example input files
run: $(TARGET)
	./$(TARGET) input1.mtx input2.mtx 0

