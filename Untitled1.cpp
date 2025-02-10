#include <iostream>
using namespace std;

// Function to perform calculations
double calculate(double num1, double num2, char op) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return (num2 != 0) ? num1 / num2 : throw invalid_argument("Cannot divide by zero");
        default: throw invalid_argument("Invalid operator");
    }
}

int main() {
    double num1, num2;
    char op;
    
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;
    
    try {
        double result = calculate(num1, num2, op);
        cout << "Result: " << result << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}
