#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{

    // struct Rectangle r={10,5};
    // //in C++, you can leave the struct
    // cout << r.length << endl;  // 10
    // cout << r.breadth << endl; // 5

    // Rectangle *p= &r;
    // cout<<p->length<<endl;
    // cout<<p->breadth<<endl;
    // return 0;

    struct Rectangle *p;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle)); // C
    // if you use C++, p=new Rectangle;
    // Now the Rectangle obj will be created in Heap
    // and Pointer will be pointing on it
    p->length = 15;
    p->breadth = 7;

    cout << p->length << endl;  // 15
    cout << p->breadth << endl; // 7
    return 0;
}
