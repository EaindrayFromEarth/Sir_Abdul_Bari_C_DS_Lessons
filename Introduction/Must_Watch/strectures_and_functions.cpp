#include <iostream>
using namespace std;

// One
// IMPORTANT: this style of coding will be used in the rest of the Course
// Because This style of Programming Lead to OOP
struct Rectangle
{
    int length;
    int breadth;
};

void initialise(struct Rectangle *r, int l, int b)
{
    r->length = l;
    r->breadth = b;
}

int area(struct Rectangle r)
{
    return r.length * r.breadth;
}

void changelength(struct Rectangle *r, int l)
{
    r->length = l;
}

int main()
{
    struct Rectangle r;

    initialise(&r, 10, 5);
    area(r);
    changelength(&r, 20);

    return 0;
}
