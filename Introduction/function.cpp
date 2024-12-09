#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
// Parameter Passing
// in C, we only have Pass by Value , Pass by Address
// in C++, we also have Pass by Reference

int add(int a, int b)
{
    int c;
    c = a + b;

    return c;
}

int main()
{

    int num1 = 10, num2 = 15, sum;
    sum = add(num1, num2);
    cout << "Sum is " << sum;
    // Explanation of function call stack:
    // - When main starts, its activation record is created in the stack.
    // - When add is called, a new activation record is created for add.
    // - Parameters num1 and num2 are passed to a and b, respectively.
    // - The result is returned to sum in main.
    // - After add finishes, its activation record is removed from the stack.
    return 0;
}
