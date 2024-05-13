#include <iostream>
#include <omp.h>

using namespace std;

#define MATRIX_SIZE 10

void fillMatrix(int matrix[][MATRIX_SIZE]) {
    
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = i * j + 1; 
        }
    }
}

void printMatrix(int matrix[][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << std::endl;
    }
}

void multiplyMatrices(int A[][MATRIX_SIZE], int B[][MATRIX_SIZE], int C[][MATRIX_SIZE]) {
#pragma omp parallel for collapse(2)
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MATRIX_SIZE][MATRIX_SIZE], B[MATRIX_SIZE][MATRIX_SIZE], C[MATRIX_SIZE][MATRIX_SIZE];

    
    fillMatrix(A);
    fillMatrix(B);

    // Print input matrices (optional)
    // cout << "Matrix A:" << std::endl;
    // printMatrix(A);
    // cout << "Matrix B:" << std::endl;
    // printMatrix(B);

    multiplyMatrices(A, B, C);

    // Print result matrix (optional)
    cout << "Result Matrix:" << std::endl;
    printMatrix(C);

    return 0;
}
