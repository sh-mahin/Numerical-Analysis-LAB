/*  
   Question:
   Find the determinant of an n x n square matrix using Gaussian Elimination.

   Steps:
   1. Convert the matrix to upper triangular form.
   2. The determinant is the product of the diagonal elements.

   Input:
   - n (size of square matrix)
   - n x n matrix elements

   Output:
   - Determinant of the matrix
*/

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

double arr[25][25]; // Matrix array (1-based indexing)

// Function to convert matrix to upper triangular form
void gaussElimination(int n) {
    for (int i = 1; i <= n; i++) {
        if (fabs(arr[i][i]) < 1e-9) {
            // Pivot is zero; determinant may be zero
            continue;
        }
        for (int r = i + 1; r <= n; r++) {
            double factor = arr[r][i] / arr[i][i];
            for (int c = i; c <= n; c++) {
                arr[r][c] -= factor * arr[i][c];
            }
        }
    }
}

// Function to compute determinant (product of diagonal elements)
double findDeterminant(int n) {
    double det = 1.0;
    for (int i = 1; i <= n; i++) {
        det *= arr[i][i];
    }
    return det;
}

int main() {
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    cout << "Enter the matrix elements:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    gaussElimination(n);

    double det = findDeterminant(n);
    cout << "\nDeterminant of the matrix: " << fixed << setprecision(6) << det << endl;

    return 0;
}
