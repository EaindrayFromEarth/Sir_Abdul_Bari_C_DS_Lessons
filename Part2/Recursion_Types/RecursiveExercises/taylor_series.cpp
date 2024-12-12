#include <stdio.h>

/*
 * Taylor Series Expansion for e^x:
 * e^x = 1 + (x / 1!) + (x^2 / 2!) + (x^3 / 3!) + ... + (x^n / n!)
 */

double e_taylor(double x, int n)
{
    double result = 1.0;
    double term = 1.0; // Holds the value of x^i / i! for each term

    for (int i = 1; i <= n; i++)
    {                   // O(n)
        term *= x / i;  // O(1)
        result += term; // O(1)
    }

    return result; // O(1)
}

//  e^x using Horner's rule
double e_horner_recursive(double x, int n, double s)
{
    if (n == 0)
    {
        return s; // O(1)
    }

    s = 1 + x * s / n;                      // O(1) using Horner's rule
    return e_horner_recursive(x, n - 1, s); // O(n)
}

int main()
{
    double x = 3;
    int n = 10;

    printf("e^%.2f (using Taylor series with %d terms): %.10f\n", x, n, e_taylor(x, n));

    double result_horner = e_horner_recursive(x, n, 1.0); // Start with s = 1.0
    printf("e^%.2f (using Horner's rule with %d terms): %.10f\n", x, n, result_horner);

    // Output 20.079665

    return 0;
}
