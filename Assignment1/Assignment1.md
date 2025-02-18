1. How did you test your code? What are the limitations of your testing?
- Using unit_tests.cpp. Limitations are that chebychev is not always a right choice to make, so in order to test it, you need to know the answer that chebychev gives, which is not always the correct approximation of the integral. 
2. What approach did you take to document your functions and driver program?
- Using Readme files.
3. How did you handle errors? Whow did you test your error handling strategy?
- If there are any errors, it should exit the code.
4. Is your code robust to errors in the input files? How did you test this?
- Yes, it would exit or give wrong input errors. 
5. Are there any limitations in your implementation you are aware of? Do you have any ideas on how
to address them?
- I can give in a file input which can be easier, or I can reduce taking the number of inputs on my command lines.
6. If you wanted to optimize the performance of your code, what approach would you take?
- I would make Polynomial definition a complete different function and would add it as a library to only call in the main function. 
7. How would you extend your code to two or more dimensions?
- Not sure.
8. Explain how you would handle a user defined function that takes additional parameters.
- Implement better strategy to store my inputs so I can differentiate and personal user-defined parameters.
9. Are there any ways you could handle arbitrary functions that are defined at runtime by the user
for example in an input file?
- The input I am taking is on the command line so I do not need/ask to define any functions.
