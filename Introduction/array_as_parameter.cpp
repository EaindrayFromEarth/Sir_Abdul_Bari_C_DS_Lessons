#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void fun(int A[], int n)
{
    // you can use for-each loop for Array
    // but you can't use for-each loop for Pointer
    // for(int a:A)
    for (int i = 0; i < n; i++)
        cout << A[i] << endl;
}

// Array Can't be parsed by Value
// Array can only be Parsed by Address
// in both C and C++

// int A[] , int *A is parsed by Address
// int n is parsed by Value

int main()
{
    int A[] = {2, 4, 6, 8, 10};
    int n = 5;
    fun(A, n);

    for (int x : A)
        cout << x << " ";
    // Output
    // 2
    // 4
    // 6
    // 8
    // 10
    // 2 4 6 8 10
    return 0;
}