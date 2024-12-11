#include <stdio.h>

// NESTED RECURSION
int fun(int n)
{

    if (n > 100)
    {
        return n - 10;
    }
    else
    {

        return fun(fun(n + 11));
    }
}

int main()
{
    int r;
    r = fun(30);
    printf("%d \n", r);
    return 0;
}

// Expected Output: 91
