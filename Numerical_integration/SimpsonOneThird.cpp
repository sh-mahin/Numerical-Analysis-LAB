/*  
   Question:
   Numerically integrate a function f(x) over the interval [a, b] using
   Simpson's 1/3 Rule with n subintervals.

   Formula:
   ∫ f(x) dx ≈ (h/3) * [ f(x0) + f(xn) + 4 * Σ f(odd xi) + 2 * Σ f(even xi) ]
   where h = (b - a)/n and n must be even

   Steps:
   1. Divide [a, b] into n subintervals (n even)
   2. Apply Simpson's 1/3 formula
   3. Return approximate value of integral
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to integrate
double func(double x) {
    return 1.0 / x;  // Example: f(x) = 1/x
}

// Simpson's 1/3 Rule function
double simpsonOneThird(double a, double b, int n) {
    if(n % 2 != 0) {
        cout << "Error: n must be even for Simpson's 1/3 Rule." << endl;
        return INFINITY;
    }

    double h = (b - a) / n;
    double sum = func(a) + func(b);

    for(int i = 1; i < n; i++) {
        double xi = a + i * h;
        if(i % 2 == 0) {
            sum += 2.0 * func(xi);  // even indices
        } else {
            sum += 4.0 * func(xi);  // odd indices
        }
    }

    return (h / 3.0) * sum;
}

int main() {
    double a, b;
    int n;

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of subintervals (n, even): ";
    cin >> n;

    double result = simpsonOneThird(a, b, n);

    if(result != INFINITY) {
        cout << fixed << setprecision(6);
        cout << "\nNumerical integration using Simpson 1/3 Rule: " << result << endl;
    }

    return 0;
}
