/*  
   Question:
   Use Newton’s Divided Difference Interpolation Method to find f(p)
   from the given data points (x, y).

   Formula:
   f(x) = f[x0] + (x - x0)f[x0,x1] + (x - x0)(x - x1)f[x0,x1,x2] + ...

   Where:
   f[xi,xj] = (f[xj] - f[xi]) / (xj - xi)
   
   Write a C++ program to:
   - Input n data points (x, y)
   - Display the divided difference table
   - Compute the interpolated value at a given point p
*/

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

// Function to compute Newton's Divided Difference interpolation
double newtonInterpolation(int n, double x[], double y[], double p) {
    double dd[100][100];  // Divided difference table

    // Initialize first column with y values
    for (int i = 0; i < n; i++) {
        dd[i][0] = y[i];
    }

    // Build the divided difference table
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            dd[i][j] = (dd[i + 1][j - 1] - dd[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    // Print the divided difference table
    cout << "\nDivided Difference Table:\n";
    cout << fixed << setprecision(6);
    for (int i = 0; i < n; i++) {
        cout << x[i] << "\t";
        for (int j = 0; j < n - i; j++) {
            cout << dd[i][j] << "\t";
        }
        cout << endl;
    }

    // Apply Newton's Interpolation Formula
    double result = dd[0][0];
    double term = 1.0;

    for (int j = 1; j < n; j++) {
        term *= (p - x[j - 1]);
        result += dd[0][j] * term;
    }

    return result;
}

// Main program
int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[100], y[100];

    cout << "Enter x values: ";
    for (int i = 0; i < n; i++) cin >> x[i];

    cout << "Enter y values: ";
    for (int i = 0; i < n; i++) cin >> y[i];

    double p;
    cout << "Enter the point to interpolate: ";
    cin >> p;

    double ans = newtonInterpolation(n, x, y, p);

    cout << "\nInterpolated value at x = " << p << " is " << ans << endl;

    return 0;
}
