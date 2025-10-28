/*  
   Question:
   Numerically integrate a function f(x) over the interval [a, b] using
   the Trapezoidal Rule with n subintervals.

   Formula:
   ∫ f(x) dx ≈ h * [ (f(x0) + f(xn))/2 + Σ f(xi) for i=1 to n-1 ]
   where h = (b - a)/n

   Steps:
   1. Divide [a, b] into n subintervals of equal width h
   2. Apply trapezoidal formula
   3. Return approximate value of integral
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double x[1000]; // Store x values

// Function to integrate
double func(double y) {
    return 1.0 / y;  // Example: f(x) = 1/x
}

// Trapezoidal rule function
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;

    // Generate x values
    x[0] = a;
    for(int i = 1; i <= n; i++) {
        x[i] = x[i - 1] + h;
    }

    // Apply trapezoidal formula
    double sum = (func(x[0]) + func(x[n])) / 2.0;

    for(int i = 1; i < n; i++) {
        sum += func(x[i]);
    }

    return h * sum;
}

int main() {
    double a, b;
    int n;

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of subintervals (n): ";
    cin >> n;

    double ans = trapezoidalRule(a, b, n);

    cout << fixed << setprecision(6);
    cout << "\nNumerical integration using Trapezoidal Rule: " << ans << endl;

    return 0;
}
