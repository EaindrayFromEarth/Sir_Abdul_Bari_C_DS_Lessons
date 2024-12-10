#include <iostream>
using namespace std;

// C++ CLass Practice
class Rectangle
{
public:
    int length;
    int breadth;

    void initialise(int l, int b)
    {
        length = l;
        breadth = b;
    }

    int area()
    {
        return length * breadth;
    }

    int perimeter()
    {
        return 2 * (length + breadth);
    }

    // Getter for area
    int getArea()
    {
        return area();
    }

    // Getter for perimeter
    int getPerimeter()
    {
        return perimeter();
    }

    // Setter for length
    void setLength(int l)
    {
        length = l;
    }

    // Setter for breadth
    void setBreadth(int b)
    {
        breadth = b;
    }
};

int main()
{
    Rectangle r;
    r.initialise(10, 5);

    cout << "Area: " << r.getArea() << endl;
    cout << "Perimeter: " << r.getPerimeter() << endl;

    // Setting new dimensions
    r.setLength(15);
    r.setBreadth(10);

    cout << "New Area: " << r.getArea() << endl;
    cout << "New Perimeter: " << r.getPerimeter() << endl;

    return 0;
}
