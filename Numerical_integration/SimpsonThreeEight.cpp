/*  
   Question:
   Numerically integrate a function f(x) over the interval [a, b] using
   Simpson's 3/8 Rule with n subintervals.

   Formula:
   ∫ f(x) dx ≈ (3h/8) * [ f(x0) + f(xn) + 3*Σ f(xi) for i not multiple of 3 + 2*Σ f(xi) for i multiple of 3 ]
   where h = (b - a)/n and n must be a multiple of 3

   Steps:
   1. Divide [a, b] into n subintervals (n multiple of 3)
   2. Apply Simpson's 3/8 formula
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

// Simpson's 3/8 Rule function
double simpsonThreeEight(double a, double b, int n) {
    if(n % 3 != 0) {
        cout << "Error: n must be a multiple of 3 for Simpson's 3/8 Rule." << endl;
        return INFINITY;
    }

    double h = (b - a) / n;
    double sum = func(a) + func(b);

    for(int i = 1; i < n; i++) {
        double xi = a + i * h;
        if(i % 3 == 0) {
            sum += 2.0 * func(xi);  // multiples of 3
        } else {
            sum += 3.0 * func(xi);  // others
        }
    }

    return (3.0 * h / 8.0) * sum;
}

int main() {
    double a, b;
    int n;

    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of subintervals (n, multiple of 3): ";
    cin >> n;

    double result = simpsonThreeEight(a, b, n);

    if(result != INFINITY) {
        cout << fixed << setprecision(6);
        cout << "\nNumerical integration using Simpson 3/8 Rule: " << result << endl;
    }

    return 0;
}
