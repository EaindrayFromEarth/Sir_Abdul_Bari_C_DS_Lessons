#include <stdio.h>

int factorial_recursive(int n)
{
    // Time complexity: O(n) - linear time due to recursive calls
    // Space complexity: O(n) - linear space due to the call stack
    if (n == 0 || n == 1)
        return 1;                          // <--- O(1) - constant time
    return n * factorial_recursive(n - 1); // <-- O(n) - n calls made
}

int factorial_iterative(int n)
{
    // Time complexity: O(n) - linear time due to the loop
    // Space complexity: O(1) - constant space
    int result = 1;              // <--- O(1) - constant time
    for (int i = 2; i <= n; i++) // <--- O(n) - loop runs n-1 times
        result *= i;             // <--- O(1) - constant time for each multiplication
    return result;               // <--- O(1) - constant time
}

int main()
{
    int n = 5;
    int r1, r2;

    r1 = factorial_recursive(n); // 120
    r2 = factorial_iterative(n); // 120

    printf("Factorial of %d (Recursive): %d\n", n, r1);
    printf("Factorial of %d (Iterative): %d\n", n, r2);

    return 0;
}
