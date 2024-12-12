#include <stdio.h>

/*
 * Taylor Series Expansion for e^x:
 * e^x = 1 + (x / 1!) + (x^2 / 2!) + (x^3 / 3!) + ... + (x^n / n!)
 * This implementation calculates e^x using n terms.
 *
 * Horner's Rule for Taylor Series:
 * e^x = 1 + x * (1/1! + x * (1/2! + x * (1/3! + ... + x * (1/n!)))
 */

double e_horner(double x, int n)
{
    // Time complexity: O(n) - linear time due to the loop
    // Space complexity: O(1) - constant space usage
    double result = 1.0;
    double term = 1.0; // Holds the value of x^i / i! for each term

    for (int i = 1; i <= n; i++)
    {                   // <--- O(n) - loop runs n times
        term *= x / i;  //  <--- O(1)
        result += term; // <---  O(1)
    }

    return result; // O(1)
}

double e(double x, int n)
{
    // Time complexity: O(n) - linear time due to recursive calls
    // Space complexity: O(n) - linear space due to the call stack
    static double p = 1;
    static double f = 1;
    double r;

    if (n == 0)   // O(1) <--- base case check
        return 1; // e^0 = 1

    r = e(x, n - 1);  // O(n) <--- recursive call (e^x for n-1)
    p = p * x;        // O(1) <--- constant time operation to update power of x
    f = f * n;        // O(1) <--- constant time operation to update factorial
    return r + p / f; // O(1)
}

int main()
{
    double x = 3;
    int n = 10;

    printf("e^%.2f (using Taylor series with %d terms): %.10f\n", x, n, e(x, n));

    printf("e^%.2f (using Taylor series with Horner's rule and %d terms): %.10f\n", x, n, e_horner(x, n));
    // Output: 20.079665
    return 0;
}
