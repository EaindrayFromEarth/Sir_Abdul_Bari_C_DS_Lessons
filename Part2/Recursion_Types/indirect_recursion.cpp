#include <stdio.h>

// INDIRECT RECURSION
void funB(int n);

void funA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funB(n - 1); // Calls funB
    }
}

void funB(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funA(n / 2); // Calls funA
    }
}

int main()
{
    funA(20); // Start the indirect recursion
    return 0;
}

// Expected Output: 20 19 9 8 4 3 1
