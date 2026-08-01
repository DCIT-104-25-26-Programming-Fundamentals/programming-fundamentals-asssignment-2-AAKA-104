// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    // Numbers less than 2 are not prime
    if (num < 2) {
        return false;
    }
    
    // 2 is the smallest prime number
    if (num == 2) {
        return true;
    }
    
    // Even numbers greater than 2 are not prime
    if (num % 2 == 0) {
        return false;
    }
    
    // Check odd divisors up to sqrt(num)
    // Using i*i <= num avoids needing sqrt() from cmath
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;  // Found a divisor, not prime
        }
    }
    
    return true;  // No divisors found, number is prime
}

int main() {
    int number;
    
    // Get input from user
    cout << "Enter a number: ";
    cin >> number;
    
    // Check if number is prime and display result
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is NOT a prime number." << endl;
    }
    
    return 0;
}
