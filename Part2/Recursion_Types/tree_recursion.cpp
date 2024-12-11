#include <stdio.h>

// Tree Recursion
void fun(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun(n - 1); // First recursive call
        fun(n - 1); // Second recursive call
    }
}

int main()
{
    fun(3);
    return 0;
}

// 3 2 1 1 2 1 1 2 1 3
