// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;


// PART A: Print the first N terms of Fibonacci sequence
void printFibonacciTerms(int n) {
    if (n <= 0) {
        cout << "Error: Number of terms must be positive." << endl;
        return;
    }
    
    cout << "Fibonacci sequence: ";
    
    if (n == 1) {
        cout << "0" << endl;
        return;
    }
    
    if (n == 2) {
        cout << "0 1" << endl;
        return;
    }
    
    // First two terms
    int first = 0;
    int second = 1;
    cout << first << " " << second;
    
    // Generate remaining terms
    for (int i = 3; i <= n; i++) {
        int next = first + second;
        cout << " " << next;
        first = second;
        second = next;
    }
    cout << endl;
}

// PART B: Check if a number belongs to Fibonacci sequence
bool isFibonacciNumber(int num) {
    if (num < 0) {
        return false;
    }
    
    if (num == 0 || num == 1) {
        return true;
    }
    
    int first = 0;
    int second = 1;
    int next = first + second;
    
    // Generate Fibonacci numbers until we reach or exceed the given number
    while (next <= num) {
        if (next == num) {
            return true;
        }
        first = second;
        second = next;
        next = first + second;
    }
    
    return false;
}

int main() {
    int choice;
    
    cout << "Fibonacci Sequence Generator" << endl;
    cout << "1. Print first N terms" << endl;
    cout << "2. Check if a number is Fibonacci" << endl;
    cout << "Enter your choice (1-2): ";
    cin >> choice;
    
    switch (choice) {
        case 1: {
            // PART A
            int n;
            cout << "How many terms? ";
            cin >> n;
            printFibonacciTerms(n);
            break;
        }
        
        case 2: {
            // PART B
            int num;
            cout << "Enter a number to check: ";
            cin >> num;
            
            if (isFibonacciNumber(num)) {
                cout << num << " is a Fibonacci number." << endl;
            } else {
                cout << num << " is NOT a Fibonacci number." << endl;
            }
            break;
        }
        
        default:
            cout << "Invalid choice. Please run the program again." << endl;
            break;
    }
    
    return 0;
}
