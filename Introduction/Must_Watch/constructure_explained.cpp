#include <iostream>
using namespace std;

// Three
// This will convert the C program to C++ class
class Rectangle // Now Structure -> Class
{               // in C++, Structure and Class are same
private:        // but in Structure , Everything is Public
    int length;
    int breadth;
    //}; // <- this is move to lowest to contain all functions

public:
    // void initialise(int l, int b) // Remove struct Rectangle r (because they are directly accessable)
    Rectangle(int l, int b) // void initialise -> Rectangle (Now Constructure)
    {
        // r->length = l;
        length = l; // Directly access class member (length and breadth)
        // r->breadth = b;
        breadth = b;
    }

    int area() // Remove struct Rectangle r
    {
        // return r.length * r.breadth;
        return length * breadth;
    }

    void changelength(int l) // Remove struct Rectangle *r
    {
        // r->length = l;
        length = l;
    }
}; // <---

int main()
{
    // Rectangle r; // Object
    //  r.initialise(10, 5);
    //  cout << "Area: " << r.area() << endl;
    //  r.changelength(20);
    //  cout << "New Area: " << r.area() << endl;

    Rectangle r(10, 5); // Direct initalzation at the time of Declaration
    // Instead of parsing length and breath later on
    // We want to parse as we create the obj
    cout << "Area: " << r.area() << endl;
    r.changelength(20);
    cout << "New Area: " << r.area() << endl;

    return 0;
}
