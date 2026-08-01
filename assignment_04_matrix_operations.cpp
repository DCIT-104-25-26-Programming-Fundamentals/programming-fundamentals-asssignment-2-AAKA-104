// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Function to read a matrix from user input
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& name) {
    cout << "Enter elements for matrix " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix in grid format
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& title) {
    cout << title << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A: Transpose a Matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int transposed[MAX_SIZE][MAX_SIZE];
    
    // Compute transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    // Display original and transposed matrices
    displayMatrix(matrix, rows, cols, "Original Matrix");
    cout << endl;
    displayMatrix(transposed, cols, rows, "Transposed Matrix");
}

// PART B: Add Two Matrices
void addMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], 
                 int rows, int cols) {
    int result[MAX_SIZE][MAX_SIZE];
    
    // Compute element-wise sum
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    
    // Display all three matrices
    displayMatrix(matrixA, rows, cols, "Matrix A");
    cout << endl;
    displayMatrix(matrixB, rows, cols, "Matrix B");
    cout << endl;
    displayMatrix(result, rows, cols, "Sum (A + B)");
}

// PART C: Multiply Two Matrices
void multiplyMatrices(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE],
                      int rowsA, int colsA, int colsB) {
    int result[MAX_SIZE][MAX_SIZE] = {0};  // Initialize all elements to 0
    
    // Compute matrix multiplication
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    
    // Display all three matrices
    displayMatrix(matrixA, rowsA, colsA, "Matrix A");
    cout << endl;
    displayMatrix(matrixB, colsA, colsB, "Matrix B");
    cout << endl;
    displayMatrix(result, rowsA, colsB, "Product (A × B)");
}

int main() {
    int choice;
    
    cout << "Matrix Operations Menu:" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    
    switch (choice) {
        case 1: {
            // PART A: Transpose
            int matrix[MAX_SIZE][MAX_SIZE];
            int rows, cols;
            
            cout << "\n--- Transpose Matrix ---" << endl;
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            
            readMatrix(matrix, rows, cols, "");
            cout << endl;
            transposeMatrix(matrix, rows, cols);
            break;
        }
        
        case 2: {
            // PART B: Add Matrices
            int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
            int rows, cols;
            
            cout << "\n--- Add Two Matrices ---" << endl;
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;
            
            readMatrix(matrixA, rows, cols, "A");
            cout << endl;
            readMatrix(matrixB, rows, cols, "B");
            cout << endl;
            addMatrices(matrixA, matrixB, rows, cols);
            break;
        }
        
        case 3: {
            // PART C: Multiply Matrices
            int matrixA[MAX_SIZE][MAX_SIZE], matrixB[MAX_SIZE][MAX_SIZE];
            int rowsA, colsA, colsB;
            
            cout << "\n--- Multiply Two Matrices ---" << endl;
            cout << "Enter rows for matrix A: ";
            cin >> rowsA;
            cout << "Enter columns for matrix A (and rows for matrix B): ";
            cin >> colsA;
            cout << "Enter columns for matrix B: ";
            cin >> colsB;
            
            readMatrix(matrixA, rowsA, colsA, "A");
            cout << endl;
            readMatrix(matrixB, colsA, colsB, "B");
            cout << endl;
            multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB);
            break;
        }
        
        default:
            cout << "Invalid choice. Please run the program again." << endl;
            break;
    }
    
    return 0;
}
