/*  
   Question:
   Solve the differential equation dy/dx = x + y
   using Euler’s Method with

   Initial conditions: x0, y0
   Step size: h = 0.1
   and for n iterations (at least 6).

   Write a C++ program to display the iteration table of x and y values.
*/

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

// Given differential equation: dy/dx = x + y
double f(double x, double y) {
    return x + y;
}

int main() {
    double x0, y0, n;

    cout << fixed << setprecision(6);
    cout << "Enter initial value of x, y, and number of iterations (n): " << endl;
    cin >> x0 >> y0 >> n;

    cout << "\nIteration\t" << "x\t\t" << "y" << endl;
    cout << "------------------------------------------" << endl;

    double x = x0, y = y0;

    for (int i = 0; i < n; i++) {
        double fx = f(x, y);
        cout << i << "\t\t" << x << "\t" << y << endl;

        // Euler formula: y_(n+1) = y_n + h * f(x_n, y_n)
        y = y + 0.1 * fx;  // step size h = 0.1
        x = x + 0.1;
    }

    cout << "------------------------------------------" << endl;
    cout << "Approximate value of y after " << n << " iterations: " << y << endl;

    return 0;
}
