## Overview
Stack Arithmetic Evaluator is a program that evaluates arithmetic expression written in postfix notation (Reverse Polish Notation). It uses a stack data structure to process the expressions.

## Features
- Supports basic arithmetic operations: addition (`+`), subtraction (`-`), multiplication, (`*`), and division (`/`).
- Handles integer inputs, including negative numbers.
- Provides error handling for invalid expressions (e.g., division by zero, insufficient operands).

## How to Use
### 1. Compile the Program  
Make sure you have a C++ compiler installed (e.g., `g++`). Compile the program with the following command:  

**g++ -o StackArithmeticEvaluator StackArithmeticEvaluator.cpp**  

This will generates an executable file.

### 2. Run the Program  
You can provide input directly in the console or via a file.  

**Option 1**: Direct Console Input  
Run the program and type the postfix expression, pressing **Enter** when done.    

**./StackArithmeticEvaluator**  

**Option 2**: Input from a File  
Create a file (e.g., `input.in`) containing your postfix expression, and pipe its contents to the program.  

**cat input.in | ./StackArithmeticEvaluator**  

### Example:  
1. Create a file **input.in** with the following content:  
5 1 2 + 4 * + 3 -  

2. Run the command:  
**cat input.in | ./StackArithmeticEvaluator**

3. Output:  
14

## Additional Notes
- Make sure the program is compiled before running any commands.