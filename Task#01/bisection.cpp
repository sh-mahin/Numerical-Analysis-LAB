/**
 * Problem Statement:
 * ------------------
 * Implement the Bisection Method in C++ to find the root of a given equation.
 * 
 * Function: f(x) = 4x³ + 3x - 3
 * 
 * Steps:
 * 1. Start with interval [a, b] such that f(a) * f(b) < 0.
 * 2. Repeatedly bisect the interval until the tolerance is satisfied.
 * 3. Print iteration details, approximate root, error, and total iterations.
 */

#include <bits/stdc++.h>
using namespace std;

// Function definition: f(x) = 4x³ + 3x - 3
double f(double x) {
    return 4 * x * x * x + 3 * x - 3;
}

// Bisection method implementation
void bisection(double a, double b, double tolerance, int max_iterations = 1000) {
    
    if (f(a) * f(b) >= 0) {
        cout << " No root found in the given interval. f(a) and f(b) must have opposite signs." << endl;
        return;
    }

    int iteration = 0;
    double c;

    
    cout << "Iter\t   a\t\t   b\t\t   c\t\t f(c)\t\t Error" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;


    while (fabs(a - b) >= tolerance && iteration < max_iterations) {
        c = (a + b) / 2.0;      // Midpoint
        double fc = f(c);       // Function value at midpoint

        
        cout << iteration + 1 << "\t"
             << a << "\t"
             << b << "\t"
             << c << "\t"
             << fc << "\t"
             << fabs(b - a) << endl;

    
        if (fabs(fc) < tolerance) {
            break;  
        }
        else if (f(a) * fc > 0) {
            a = c;  
        } else {
            b = c;  
        }

        iteration++;
    }


    cout << "\nApproximate Root: " << c << endl;
    cout << "± Approximate Error: " << (b - a) / 2.0 << endl;
    cout << "Number of Iterations: " << iteration << endl;
}




int main() {
    double a, b;
    cout << "Enter interval [a b]: ";
    cout<< fixed << setprecision(6);
    cin >> a >> b;

    double tolerance = 1e-6;  

    bisection(a, b, tolerance);

    return 0;
}
