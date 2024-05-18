#include <iostream>
#include <array>

using namespace std;

// Function to multiply two matrices using Strassen's algorithm
template<size_t N>
void strassen_multiply(int A[N][N], int B[N][N], int C[N][N]) {
    // Base case: if the matrix size is 1x1
    if (N == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Divide matrices A and B into four submatrices
    constexpr size_t half = N / 2;

    int A11[half][half], A12[half][half], A21[half][half], A22[half][half];
    int B11[half][half], B12[half][half], B21[half][half], B22[half][half];

    // Divide matrices A and B into submatrices
    for (size_t i = 0; i < half; i++) {
        for (size_t j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    // Compute the seven products recursively
    int P1[half][half], P2[half][half], P3[half][half], P4[half][half], P5[half][half], P6[half][half], P7[half][half];
    strassen_multiply(half, A11, sub_matrix(B12, B22, half), P1);
    strassen_multiply(half, add_matrices(half, A11, A12), B22, P2);
    strassen_multiply(half, add_matrices(half, A21, A22), B11, P3);
    strassen_multiply(half, A22, sub_matrix(B21, B11, half), P4);
    strassen_multiply(half, add_matrices(half, A11, A22), add_matrices(half, B11, B22), P5);
    strassen_multiply(half, sub_matrices(half, A12, A22), add_matrices(half, B21, B22), P6);
    strassen_multiply(half, sub_matrices(half, A11, A21), add_matrices(half, B11, B12), P7);

    // Compute the result submatrices
    int C11[half][half], C12[half][half], C21[half][half], C22[half][half];
    add_matrices(half, sub_matrices(half, add_matrices(half, P5, P4), P2), P6, C11);
    add_matrices(half, P1, P2, C12);
    add_matrices(half, P3, P4, C21);
    add_matrices(half, sub_matrices(half, add_matrices(half, P5, P1), add_matrices(half, P3, P7)), P2, C22);

    // Combine the result submatrices into the result matrix
    for (size_t i = 0; i < half; i++) {
        for (size_t j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
}

// Function to add two matrices
template<size_t N>
void add_matrices(size_t size, int A[N][N], int B[N][N], int C[N][N]) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
template<size_t N>
int sub_matrices(size_t size, int A[N][N], int B[N][N], int C[N][N]) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to print a matrix
template<size_t N>
void print_matrix(int matrix[N][N]) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the matrices: ";
    cin >> n;

    int A[n][n], B[n][n], C[n][n];

    cout << "Enter the elements of matrix A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter the elements of matrix B:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    // Multiply matrices using Strassen's algorithm
    strassen_multiply(n, A, B, C);

    cout << "Resultant matrix C:" << endl;
    print_matrix(n, C);

    return 0;
}

