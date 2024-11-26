#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

// Function initialisation
bool isNumber(string currentValue);
void evaluateExpression(const string& expression);

int main(){

    string expression;
    getline(cin, expression);
    evaluateExpression(expression);
    return 0;
}

// Function to check if the current string is a number
bool isNumber(string currentValue){
    for (int i = 0; i < (int)currentValue.length(); i++){
        // Check if the current character is a digit, if it is not, then check if it is a negative number (if it is, then it is still a number)
        if (isdigit(currentValue[i]) == false){
            
            // Check if the current value is a negative number by checking the first character is a dash, and length of the current value is bigger than 1.
            bool isNegativeNumber;
            isNegativeNumber = ((currentValue[i] == '-') && (currentValue.length() > 1)); 
            
            if (isNegativeNumber == false) {
                return false;
            }
        }
    }
    return true;
}

// Function to evaluate the expression
void evaluateExpression(const string& expression){

    stack<int> integerStack;
    stringstream theFullInput(expression);
    string currentValue;
    int number1, number2, result;

    // Process the input expression (delimited by space)
    while (getline(theFullInput, currentValue, ' ')){

        // Check if current value is a number
        if (isNumber(currentValue)){

            // If current value is a number, convert it to integer, and push it to the stack
            integerStack.push(stoi(currentValue));

        // If current value is an operator
        } else if (currentValue == "+" || currentValue == "-" || currentValue == "*" || currentValue == "/"){
            
            // Check if the stack has less than 2 elements, if it does, then the expression is invalid (not enough operands for the operator)
            if (integerStack.size() < 2){
                cout << "INVALID: Not enough operands for the operator " << currentValue << endl;
                exit(12);
            }

            // Get the both top elements from the stack
            number1 = integerStack.top();
            integerStack.pop();
            number2 = integerStack.top();
            integerStack.pop();

            // Check the operator, and apply the calculation accordingly
            if (currentValue == "+"){
                result = number2 + number1;
            } else if (currentValue == "-"){
                result = number2 - number1;
            } else if (currentValue == "*"){
                result = number2 * number1;
            } else if (currentValue == "/"){

                // Check if denominator is 0 for invalid division
                if (number1 == 0){
                    cout << "INVALID: Division by zero" << endl;
                    return;
                }
                result = number2 / number1;
            }

            // Push the result back to the stack
            integerStack.push(result);

        } else {
            cout << "INVALID: Unknown operator " << currentValue << endl;
            return;
        }
    }

    // Final check, if there is more than 1 element in the stack, then the expression is invalid
    if (integerStack.size() != 1){
        cout << "INVALID: The expression is not well-formed." << endl;
    } else {
        cout << integerStack.top();
    }

}