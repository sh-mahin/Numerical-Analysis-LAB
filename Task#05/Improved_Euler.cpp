/*  
   Question:
   Solve the differential equation dy/dx = x + y
   using the **Improved Euler Method (Heun’s Method)** with

   Initial conditions: x0, y0
   Step size: h = 0.1
   and for n iterations (at least 6).

   Write a C++ program to display the iteration table of x and y values.
   
   Formula used:
   Predictor: y_pred = y_n + h * f(x_n, y_n)
   Corrector: y_(n+1) = y_n + (h/2) * [ f(x_n, y_n) + f(x_(n+1), y_pred) ]
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

    double h = 0.1; // Step size
    double x = x0, y = y0;

    cout << "\nIteration\t" << "x\t\t" << "y" << endl;
    cout << "------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        double f1 = f(x, y);                 // f(x_n, y_n)
        double y_pred = y + h * f1;          // Predictor
        double f2 = f(x + h, y_pred);        // f(x_(n+1), y_pred)
        double y_new = y + (h / 2.0) * (f1 + f2);  // Corrector

        cout << i << "\t\t" << x << "\t" << y << endl;

        // Update values for next iteration
        y = y_new;
        x = x + h;
    }

    cout << "------------------------------------------" << endl;
    cout << "Approximate value of y after " << n << " iterations: " << y << endl;

    return 0;
}
