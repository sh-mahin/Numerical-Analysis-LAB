/*  
   Question:
   Solve a system of linear equations using Gaussian Elimination with partial pivoting.

   Input:
   - n equations and m unknowns
   - Augmented matrix (n x (m+1))

   Steps:
   1. Forward elimination to convert matrix to upper triangular
   2. Partial pivoting for numerical stability
   3. Back substitution to find the solution vector

   Output:
   - Solution vector x[1..n] with each unknown's value
*/

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

double arr[25][25]; // Augmented matrix (1-based indexing)
double x[25];       // Solution vector (1-based indexing)

// Gaussian elimination function
void gaussElimination(int n, int m) {
    int prow = 1, pcol = 1;

    // Forward elimination with partial pivoting
    while (pcol <= m && prow <= n) {

        int pivot = prow;
        for (int i = prow + 1; i <= n; i++) {
            if (fabs(arr[i][pcol]) > fabs(arr[pivot][pcol])) {
                pivot = i;
            }
        }

        // Skip column if pivot is zero
        if (fabs(arr[pivot][pcol]) < 1e-9) {
            pcol++;
            continue;
        }

        // Swap pivot row to current position
        if (pivot != prow) {
            for (int j = 1; j <= m + 1; j++) {
                swap(arr[pivot][j], arr[prow][j]);
            }
        }

        // Eliminate rows below pivot
        for (int i = prow + 1; i <= n; i++) {
            double factor = arr[i][pcol] / arr[prow][pcol];
            for (int j = pcol; j <= m + 1; j++) {
                arr[i][j] -= factor * arr[prow][j];
            }
        }

        prow++;
        pcol++;
    }

    // Back substitution
    x[n] = arr[n][m + 1] / arr[n][n];
    for (int i = n - 1; i >= 1; i--) {
        x[i] = arr[i][m + 1];
        for (int j = i + 1; j <= m; j++) {
            x[i] -= arr[i][j] * x[j];
        }
        x[i] /= arr[i][i];
    }
}

int main() {
    int n = 3, m = 3;

    cout << "Enter augmented matrix (size " << n << "x" << m+1 << "):" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m + 1; j++) {
            cin >> arr[i][j];
        }
    }

    gaussElimination(n, m);

    cout << "\nSolution:\n";
    for (int i = 1; i <= n; i++) {
        cout << "x[" << i << "] = " << fixed 
             << setprecision(5) << x[i] << endl;
    }

    return 0;
}
