/*  
   Question:
   Use the Lagrange Interpolation Method to find the value of f(x) 
   at a given point 'p' based on the given data points (x, y).

   Formula:
   f(p) = Σ [ y_i * L_i(p) ]   for i = 0 to n-1
   where
   L_i(p) = Π [(p - x_j) / (x_i - x_j)] for all j ≠ i

   Write a C++ program to:
   - Take n data points (x, y)
   - Input the point p
   - Compute and display the interpolated value f(p)
*/

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

// Function for Lagrange interpolation
double lagrange(int n, double p, double x[], double y[]) {
    double px = 0.0; // Result

    for (int i = 0; i < n; i++) {
        double li = 1.0; // L_i(p)
        for (int j = 0; j < n; j++) {
            if (j != i) {
                li *= (p - x[j]) / (x[i] - x[j]);
            }
        }
        px += li * y[i]; // Add contribution of term i
    }

    return px;
}

int main() {
    int n;

    cout << "Enter the number of data points: ";
    cin >> n;

    double x[1000], y[1000];

    cout << "Enter x values: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter y values: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    double p;
    cout << "Enter the point to interpolate: ";
    cin >> p;

    double result = lagrange(n, p, x, y);

    cout << fixed << setprecision(6);
    cout << "\nInterpolated value at x = " << p << " is " << result << endl;

    return 0;
}
