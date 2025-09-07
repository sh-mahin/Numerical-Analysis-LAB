/**
 * Problem Statement:
 * ------------------
 * Implement the Newton-Raphson Method in C++ to find the root of:
 *
 *      f(x) = x^5 - 3x + 5 
 *      tolerance = 1e-3
 *
 * Steps:
 * 1. Start with an initial guess x0.
 * 2. Iterate using the formula:
 *        x1 = x0 - f(x0) / f'(x0)
 * 3. Stop when |x1 - x0| < tolerance or max iterations reached.
 * 4. Print iteration details, approximate root, and f(root).
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double f(double x) {
    return pow(x, 5) - 3*x + 5;   // f(x) = x^5 - 3x + 5
}

double df(double x) {
    return 5*pow(x, 4) - 3;       // f'(x) = 5x^4 - 3
}


void newton_raphson(double x0, double tol = 1e-6, int max_iter = 100) {
    double x1;
    int iteration = 0;

    cout << fixed << setprecision(6);
    cout << "Iter\t   x0\t\t   x1\t\t f(x1)\n";
    cout << "-------------------------------------------------------------\n";

    while (iteration < max_iter) {
       
        if (df(x0) == 0) {
            cout << "Derivative is zero at x = " << x0 << ". Stopping.\n";
            return;
        }

       
        x1 = x0 - f(x0) / df(x0);

        
        cout << iteration + 1 << "\t"
             << x0 << "\t"
             << x1 << "\t"
             << f(x1) << endl;

       
        if (fabs(x1 - x0) < tol) {
            break;
        }

        x0 = x1;
        iteration++;
    }

    cout << "\n Approximate root: " << x1 
         << " after " << iteration + 1 << " iterations.\n";
    cout << "f(root) = " << f(x1) << endl;
}


int main() {
    double x0;

   
    cout << "Enter the initial guess (x0): ";
    cin >> x0;

    newton_raphson(x0);

    return 0;
}
