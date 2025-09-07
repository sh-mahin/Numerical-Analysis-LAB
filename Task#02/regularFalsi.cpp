/**
 * Problem Statement:
 * ------------------
 * Implement the False Position (Regula Falsi) Method in C++ to find the root of:
 * 
 *      f(x) = ln(3x) - 3      tolerance = 1e-4
 * 
 * Steps:
 * 1. Start with interval [a, b] such that f(a) * f(b) < 0.
 * 2. Apply the formula:
 *        c = (a*f(b) - b*f(a)) / (f(b) - f(a))
 * 3. Repeat until tolerance is satisfied or max iterations reached.
 * 4. Print iteration details, approximate root, error, and total iterations.
 */

#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
using namespace std;

// Function definition: f(x) = ln(3x) - 3
double f(double x) {
    return log(3 * x) - 3;
}

// False Position (Regula Falsi) Method
void false_position(double a, double b, double tolerance, int max_iterations = 1000) {
    
    if (f(a) * f(b) > 0) {
        cout << "Root not guaranteed in the given interval [a, b]." << endl;
        return;
    }

    double c; // Approximate root
    int iteration = 0;

    // Print table header
    cout << "Iter\t   a\t\t   b\t\t   c\t\t f(c)\t\t Error" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    
    while ((b - a) >= tolerance && iteration < max_iterations) {
        // False position formula
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        double fc = f(c);

       
        cout << iteration + 1 << "\t"
             << a << "\t"
             << b << "\t"
             << c << "\t"
             << fc << "\t"
             << fabs(b - a) << endl;

       
        if (fabs(fc) < tolerance)
            break;
        else if (f(a) * fc > 0)
            a = c;   
        else
            b = c;  

        iteration++;
    }

    
    cout << "\n Approximate Root: " << c << endl;
    cout << "± Approximate Error: " << (b - a) << endl;
    cout << " Number of Iterations: " << iteration << endl;
}


int main() {
    double a = 3, b = 7;          
    double tolerance = 1e-4; 
    cout << fixed << setprecision(6);     

    false_position(a, b, tolerance);

    return 0;
}
