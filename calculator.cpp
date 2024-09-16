#include <iostream>
#include <limits> // For numeric limits
using namespace std;

int main() {
    char operation;
    double num1, num2;

    // Function to get valid number input
    auto getNumber = []() -> double {
        double num;
        while (true) {
            cin >> num;
            if (!cin.fail()) break;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input, please enter a number: ";
        }
        return num;
    };

    // Input operator
    cout << "Enter operator (+, -, *, /): ";
    cin >> operation;

    // Validate operator
    if (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
        cout << "Invalid operator!" << endl;
        return 1;
    }

    // Input numbers
    cout << "Enter first number: ";
    num1 = getNumber();

    cout << "Enter second number: ";
    num2 = getNumber();

    // Perform calculation and display result
    cout << "Result: ";
    switch (operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            else
                cout << "Error! Division by zero." << endl;
            break;
    }

    return 0;
}