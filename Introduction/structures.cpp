#include <iostream>
#include <stdio.h>
using namespace std;

// struct Rectangle
// {
//     int length;
//     int breadth;
// } r1,r2,r3;   //This way works too!

struct Rectangle
{
    int length;  //4 bytes
    int breadth; //4 bytes
    //char x; //4 bytes (if you uncomment this, 12 bytes)
};

int main()
{
    struct Rectangle r1={10,5};
    
    printf("%lu",sizeof(r1));
    //output = 8
    //8 bytes
    
    cout << r1.length <<endl; //10
    cout << r1.breadth <<endl; //5
    
    r1.length=15;
    r1.breadth=7;
    cout << r1.length <<endl; //15
    cout << r1.breadth <<endl; //7

    return 0;
}
