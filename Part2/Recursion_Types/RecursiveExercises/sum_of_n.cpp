#include <stdio.h>

// Sum of N
int sumn(int n)
{
    // Time complexity: O(1) - constant time
    // Space complexity: O(1) - constant space
    return n * (n + 1) / 2; // Sum using the formula
}

int sum(int n)
{
    // Time complexity: O(n) - linear time due to recursive calls
    // Space complexity: O(n) - linear space due to the call stack
    if (n == 0)
        return 0;          // Base case
    return sum(n - 1) + n; // Recursive case
}

int Isum(int n)
{
    // Time complexity: O(n) - linear time due to the loop
    // Space complexity: O(1) - constant space
    int s = 0;
    for (int i = 1; i <= n; i++)
        s = s + i; // Sum from 1 to n
    return s;
}

int main()
{
    int r1, r2, r3;
    r1 = sum(5);  // Recursive sum
    r2 = Isum(5); // Iterative sum
    r3 = sumn(5); // Sum using the formula
    printf("Recursive sum: %d\n", r1);
    printf("Iterative sum: %d\n", r2);
    printf("Formula sum: %d\n", r3);
    return 0;
}
