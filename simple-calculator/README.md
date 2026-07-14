# Simple Calculator
This readme file will go over the use and instructions, as well as the known faults of the Simple Calculator progam. We will be discussing expected input parameters, illegal actions and describe the expected outcomes.

# Compile command
The following is the exact compile command use to compile calculator.c
- gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator

# Run instructions
When running the executable file, the user is presented with a menu of options, and the interface will wait on user input before executing any other actions.

Simple Calculator
1) Add
2) Subtract
3) Multiply
4) Divide
0) Quit

- Legal inputs are: 0, 1, 2, 3, 4.
- Inputting any other number will prompt for a new legal number.
- Inputting a character will print error and terminate the program.
Once inputted a legal value, the program will then prompt the user to input two variables 'A' and 'B', and will then proceed to calculate the selected operation, printing the result.

# Supported operations
Addition, Subtraction, Multiplication and Division are the only supported operations. 

# Numeric behavior
All operations run as integer values, with the exception of division, running its operation as float, printing only the first decimal digit.

# Known limitations
Current program iteration does not support inputting any other character other than a number (float) as one of the operands. This will cause the program to terminate and print a wrong result. Additionally, when inputting a sequence of numbers separated by a space when prompted for the operands, the program will always take the first two numbers as it's scanned values, no matter the amount of numbers prompted. If this is inputted when prompted for the value 'A' it will skip asking for 'B'  
