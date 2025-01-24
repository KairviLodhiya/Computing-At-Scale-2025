### Answering the questions

#### a. Testing the Code
I tested my code using `testScript.cpp`, where I created two test cases:
1. **Matrix-Vector Multiplication**
2. **Matrix-Matrix Multiplication**
The program runs successfully for most cases, except when a matrix or vector is completely zero.


#### b. Limitations of Matrix Market
1. **Storage format for Dense Matrix is not very effective.**
2. **Not very practical for large dense matrix**
3. **Error checking is limited**


#### c. Advantage of Knowing the Size
Knowing the size of the matrices at compile time provides several advantages:
- I would be able to add precise error statements for handling matrices of the given size, ensuring any incorrect input immediately terminates the program.
- I would use fixed-sized containers, avoiding unnecessary memory allocation during initialization, which improves both efficiency and performance.


#### d. Row-Major Matrix
My matrix representation was row-major because:
- Row-major representation is a natural way of implementation in C++/Java environments.
- As this was a generic multiplication function, row-major representation simplifies calculations since row-by-row iteration is more intuitive compared to column-by-column iteration.
- While column-major representation might be more useful in specific algebraic calculations, row-major suits the context of this implementation.


#### e. Documentation
- I used `README.md` to document my function and driver files, providing detailed instructions for compilation, usage, and testing.


#### f. Code Robustness
- I have incorporated extensive error handling to ensure the program maintains input requirements effectively.
- However, error handling is not included in my testing file, as I manually tested input errors.


#### g. Limitations in My Implementation
- The main limitation is handling cases where text is added in place of numbers in the input files. The code currently fails without providing an error message for such scenarios.
- Other than this, I believe my code can handle large matrices effectively. At present, I am unaware of other potential issues in matrix handling.


#### h. Optimizing My Code
To optimize my code further:
- I would combine vector and matrix multiplication into a single universal function to handle both types of inputs seamlessly.
- I would minimize repeated calculations by precomputing or reusing intermediate results, reducing computational overhead and improving efficiency.
