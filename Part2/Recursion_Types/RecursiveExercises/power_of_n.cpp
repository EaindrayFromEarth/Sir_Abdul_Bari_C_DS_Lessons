#include <stdio.h>

int power_recursive(int m, int n)
{
    // Time complexity: O(n) - linear time due to recursive calls
    // Space complexity: O(n) - linear space due to the call stack
    if (n == 0)
        return 1;                         // <--- O(1) - constant time
    return m * power_recursive(m, n - 1); // <--- O(n) - n calls made
}

int power_iterative(int m, int n)
{
    // Time complexity: O(n) - linear time due to the loop
    // Space complexity: O(1) - constant space
    int result = 1;             // <--- O(1) - constant time
    for (int i = 0; i < n; i++) // <--- O(n) - loop runs n times
        result *= m;            // <--- O(1) - constant time for each multiplication
    return result;              // <--- O(1) - constant time
}

int power_exponentiation_by_squaring(int m, int n)
{
    // Time complexity: O(log n) - logarithmic time due to halving n
    // Space complexity: O(log n) - logarithmic space due to the call stack
    if (n == 0)
        return 1; // O(1) - constant time

    if (n % 2 == 0)
        return power_exponentiation_by_squaring(m * m, n / 2); // O(log n)

    return m * power_exponentiation_by_squaring(m * m, (n - 1) / 2); // O(log n)
}

int main()
{
    int m = 2;
    int n = 5;
    int r1, r2, r3;

    r1 = power_recursive(m, n);                  // 32 (2^5)
    r2 = power_iterative(m, n);                  // 32 (2^5)
    r3 = power_exponentiation_by_squaring(m, n); // 32 (2^5)

    printf("%d raised to the power of %d (Recursive): %d\n", m, n, r1);
    printf("%d raised to the power of %d (Iterative): %d\n", m, n, r2);
    printf("%d raised to the power of %d (Exponentiation by Squaring): %d\n", m, n, r3);

    return 0;
}
