// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

// Function to get two numbers from user
void getTwoNumbers(double& num1, double& num2) {
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
}

// Addition function
double add(double a, double b) {
    return a + b;
}

// Subtraction function
double subtract(double a, double b) {
    return a - b;
}

// Multiplication function
double multiply(double a, double b) {
    return a * b;
}

// Division function
double divide(double a, double b) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero." << endl;
        return 0;
    }
    return a / b;
}

// Modulus function (works with integers)
int modulus(int a, int b) {
    if (b == 0) {
        cout << "Error: Cannot perform modulus with zero." << endl;
        return 0;
    }
    return a % b;
}

// Exponentiation function
double power(double base, double exponent) {
    return pow(base, exponent);
}

int main() {
    int choice;
    double num1, num2;
    double result;
    
    cout << "Welcome to the Simple Calculator!" << endl;
    cout << fixed << setprecision(2);
    
    // Main program loop
    while (true) {
        displayMenu();
        cin >> choice;
        
        // Validate input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 7." << endl;
            continue;
        }
        
        // Process user choice
        switch (choice) {
            case 1: {  // Addition
                getTwoNumbers(num1, num2);
                result = add(num1, num2);
                cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            }
            
            case 2: {  // Subtraction
                getTwoNumbers(num1, num2);
                result = subtract(num1, num2);
                cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            }
            
            case 3: {  // Multiplication
                getTwoNumbers(num1, num2);
                result = multiply(num1, num2);
                cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            }
            
            case 4: {  // Division
                getTwoNumbers(num1, num2);
                if (num2 == 0) {
                    divide(num1, num2);  // This will print the error message
                } else {
                    result = divide(num1, num2);
                    cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
                }
                break;
            }
            
            case 5: {  // Modulus
                int int1, int2;
                cout << "Enter first number (integer): ";
                cin >> int1;
                cout << "Enter second number (integer): ";
                cin >> int2;
                
                if (int2 == 0) {
                    modulus(int1, int2);  // This will print the error message
                } else {
                    int modResult = modulus(int1, int2);
                    cout << "Result: " << int1 << " % " << int2 << " = " << modResult << endl;
                }
                break;
            }
            
            case 6: {  // Exponentiation
                getTwoNumbers(num1, num2);
                result = power(num1, num2);
                cout << "Result: " << num1 << " ^ " << num2 << " = " << result << endl;
                break;
            }
            
            case 7:  // Quit
                cout << "Goodbye!" << endl;
                return 0;
                
            default:
                cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
                break;
        }
    }
    
    return 0;
}
