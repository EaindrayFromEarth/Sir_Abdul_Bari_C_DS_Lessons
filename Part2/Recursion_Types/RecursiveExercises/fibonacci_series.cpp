#include <stdio.h>

/*
 * Fibonacci Series:
 * F(n) = F(n-1) + F(n-2) for n > 1
 * F(0) = 0, F(1) = 1
 */

int fib_iterative(int n)
{
    // Time complexity: O(n) - linear time due to the loop
    // Space complexity: O(1) - constant space
    if (n <= 1)
    {
        return n; // <--- O(1)
    }

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {              // <--- O(n)
        c = a + b; // <--- O(1)
        a = b;     // <--- O(1)
        b = c;     // <--- O(1)
    }

    return b; // <--- O(1)
}

int fib_recursive(int n)
{
    // Time complexity: O(2^n) - exponential time due to recursive calls
    // Space complexity: O(n) - linear space due to the call stack
    if (n <= 1)
    {
        return n; // <--- O(1)
    }

    return fib_recursive(n - 1) + fib_recursive(n - 2); // <--- O(2^n)
}

// Memoization version of Fibonacci series
int f[100]; // to store Fibonacci numbers

int fib_memoization(int n)
{
    // Time complexity: O(n) - linear time due to memoization
    // Space complexity: O(n) - linear space due to the call stack and storage array
    if (n <= 1)
    {
        f[n] = n; // <--- O(1)
        return n; // <--- O(1)
    }

    if (f[n - 2] == -1)
    {                                      // <--- O(1)
        f[n - 2] = fib_memoization(n - 2); // <--- O(n)
    }
    if (f[n - 1] == -1)
    {                                      // <--- O(1)
        f[n - 1] = fib_memoization(n - 1); // <--- O(n)
    }
    return f[n - 2] + f[n - 1]; // <--- O(1)
}

int main()
{
    int n = 10;

    // Iterative Fibonacci
    printf("Fibonacci of %d (iterative): %d\n", n, fib_iterative(n));

    // Recursive Fibonacci
    printf("Fibonacci of %d (recursive): %d\n", n, fib_recursive(n));

    // Memoization Fibonacci
    for (int i = 0; i < 100; i++)
    {
        f[i] = -1; // <--- O(1)
    }
    printf("Fibonacci of %d (memoization): %d\n", n, fib_memoization(n));

    return 0;
}
