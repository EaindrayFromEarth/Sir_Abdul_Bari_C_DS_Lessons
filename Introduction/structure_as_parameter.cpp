#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void funByValue(struct Rectangle rect)
{
    rect.length = 20;
    cout << "Length: " << rect.length << endl;
    cout << "Breadth: " << rect.breadth << endl;
}

// Function to parse the structure by address
void funByAddress(struct Rectangle *p)
{
    p->length = 20;
    cout << "Length: " << p->length << endl;
    cout << "Breadth: " << p->breadth << endl;
}

int main()
{
    struct Rectangle r = {10, 5};

    funByValue(r);
    cout << "After funByValue:" << endl;
    printf("Length: %d \nBreadth: %d \n", r.length, r.breadth); // Original values remain unchanged

    funByAddress(&r);
    cout << "After funByAddress:" << endl;
    printf("Length: %d \nBreadth: %d \n", r.length, r.breadth); // Original values are modified

    return 0;
}
