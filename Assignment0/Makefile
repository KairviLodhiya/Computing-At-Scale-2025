# Compiler and flags
CXX = g++
CC = gcc
CXXFLAGS = -Wall -g

# Target executable
TARGET = matrix_operations

# Object files
OBJECTS = main.o matrixMultiply.o mmio.o

# Default target: compile and link the program
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

# Compile the main driver
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile matrixMatrixProduct
matrixMatrixProduct.o: matrixMultiply.cpp
	$(CXX) $(CXXFLAGS) -c matrixMultiply.cpp

# Compile mmio
mmio.o: mmio.c
	$(CC) -c mmio.c

# Clean the build
clean:
	rm $(TARGET) $(OBJECTS)

# Run the program with example input files
run: $(TARGET)
	./$(TARGET) input1.mtx input2.mtx 0

