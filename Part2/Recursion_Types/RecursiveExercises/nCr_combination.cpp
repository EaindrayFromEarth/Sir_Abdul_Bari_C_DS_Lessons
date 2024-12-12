#include <stdio.h>

/*
 * Binomial Coefficient:
 * nCr = n! / (r! * (n - r)!)
 */

int fact(int n)
{
    // Time complexity: O(n) - linear time due to the loop
    // Space complexity: O(1) - constant space
    if (n <= 1)
    {
        return 1; // <--- O(1)
    }
    int result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i; // <--- O(1)
    }
    return result; // <--- O(1)
}

// Function  nCr using factorial
int nCr_factorial(int n, int r)
{
    // Time complexity: O(n) - linear time due to factorial calculations
    // Space complexity: O(1) - constant space
    if (r > n)
    {
        return 0; // <--- O(1)
    }
    int num = fact(n);               // <--- O(n)
    int den = fact(r) * fact(n - r); // <--- O(n)
    return num / den;                // <--- O(1)
}

// Recursive nCr
int nCr_recursive(int n, int r)
{
    // Time complexity: O(2^n) - exponential time due to recursive calls
    // Space complexity: O(n) - linear space due to the call stack
    if (n == r || r == 0)
    {
        return 1; // <--- O(1)
    }
    return nCr_recursive(n - 1, r - 1) + nCr_recursive(n - 1, r); // <--- O(2^n)
}

int main()
{
    int n = 5, r = 2;

    // nCr using factorial
    printf("nCr of %d and %d (factorial method): %d\n", n, r, nCr_factorial(n, r));

    // nCr using recursion
    printf("nCr of %d and %d (recursive method): %d\n", n, r, nCr_recursive(n, r));
    // 10

    return 0;
}
