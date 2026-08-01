// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

// PART A: Print multiplication table for a single number
void printTable(int num) {
    cout << "Multiplication Table for " << num << ":" << endl;
    for (int i = 1; i <= 12; i++) {
        cout << num << "  x  " << setw(2) << i << "  =  " << num * i << endl;
    }
}

// PART B: Print multiplication tables from 1 to N
void printTablesUpToN(int n) {
    if (n <= 0) {
        cout << "Error: Number must be positive." << endl;
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        printTable(i);
        if (i < n) {
            cout << "---------------------------" << endl;
        }
    }
}

int main() {
    int choice;
    
    cout << "Multiplication Table Generator" << endl;
    cout << "1. Print table for a single number" << endl;
    cout << "2. Print tables from 1 to N" << endl;
    cout << "Enter your choice (1-2): ";
    cin >> choice;
    
    switch (choice) {
        case 1: {
            // PART A
            int num;
            cout << "Enter a number: ";
            cin >> num;
            cout << endl;
            printTable(num);
            break;
        }
        
        case 2: {
            // PART B
            int n;
            cout << "Enter a number N: ";
            cin >> n;
            
            if (n <= 0) {
                cout << "Error: Number must be positive." << endl;
                return 1;
            }
            
            cout << endl;
            printTablesUpToN(n);
            break;
        }
        
        default:
            cout << "Invalid choice. Please run the program again." << endl;
            break;
    }
    
    return 0;
}

