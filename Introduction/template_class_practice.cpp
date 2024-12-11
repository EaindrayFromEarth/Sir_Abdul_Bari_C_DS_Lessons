#include <iostream>
using namespace std;

// Template class

// The use of <class T>
// allows this class to work with any data type (int, float, double, etc.)
// T -> a placeholder for a data type
// making the class generic and reusable
template <class T>
class Arithmetic
{
private:
    T a; // Variable 'a' of type T
    T b; // Variable 'b' of type T

public:
    // Constructor
    // The constructor accepts parameters of type T, allowing flexibility in the types of inputs
    Arithmetic(T a, T b);

    // Methods
    // matching the data type of the input parameters
    T add();
    T sub();
};

// Constructor definition
// Here, 'this->a' and 'this->b' refer to the class members,
// while 'a' and 'b' are the arguments passed to the constructor
template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

// Method to add two numbers of type T
template <class T>
T Arithmetic<T>::add()
{
    T c; // Temporary variable of type T
    c = a + b;
    return c;
}

// Method to subtract two numbers of type T
template <class T>
T Arithmetic<T>::sub()
{
    T c; // Temporary variable of type T to store the result
    c = a - b;
    return c;
}

// Main function
int main()
{
    // Create objects for different data types

    // Object with integer type (int)
    // Arithmetic<int> uses 'int' for T,
    // so all operations are performed on integers
    Arithmetic<int> intCalc(10, 5);
    cout << "Integer addition: " << intCalc.add() << endl;    // Output: 15
    cout << "Integer subtraction: " << intCalc.sub() << endl; // Output: 5

    // Object with floating-point type (float)
    // Arithmetic<float> uses 'float' for T, enabling operations on floating-point numbers
    Arithmetic<float> floatCalc(10.5, 5.2);
    cout << "Float addition: " << floatCalc.add() << endl;    // Output: 15.7
    cout << "Float subtraction: " << floatCalc.sub() << endl; // Output: 5.3

    return 0;
}
