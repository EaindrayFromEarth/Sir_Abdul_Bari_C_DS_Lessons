#include <iostream>
using namespace std;

// in C, we only have Pass by Value , Pass by Address
// in C++, we also have Pass by Reference

// Parse by Address
void swap1(int *x1, int *y1)
{
    int temp1;
    temp1 = *x1;
    *x1 = *y1;
    *y1 = temp1;
}

// Parse by Reference
void swap2(int &x2, int &y2)
{
    int temp2;
    temp2 = x2;
    x2 = y2;
    y2 = temp2;
} // Reference is like Nickname (doesn't take any Memory)
//(So, it may become INLINE function) depends on Compilers
// Don't use Call by Reference in Complex functions

// void swap3(int &x2, int *y2) //this is also Possible

int main()
{
    int num1 = 10, num2 = 15;
    swap1(&num1, &num2);
    cout << "First number: " << num1 << endl;
    cout << "Second number: " << num2 << endl;
    // First number: 15
    // Second number: 10

    int num3 = 10, num4 = 15;
    swap2(num3, num4);
    cout << "First number: " << num3 << endl;
    cout << "Second number: " << num4 << endl;
    // First number: 15
    // Second number: 10

    return 0;
}
