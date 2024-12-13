#include <iostream>
using namespace std;

// Template class for a dynamic array
template <class T>
class Array
{
private:
    T *A;     // Pointer to the array of type T
    int size; // Maximum size of the array
    int length;

public:
    Array()
    {
        size = 10;
        A = new T[10];
        length = 0;
    }

    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new T[size];
    }

    ~Array()
    {
        delete[] A;
    }

    void Display();

    void Insert(int index, T x);

    T Delete(int index);
};

template <class T>
void Array<T>::Display()
{
    for (int i = 0; i < length; i++)
        cout << A[i] << " ";
    cout << endl;
}

template <class T>
void Array<T>::Insert(int index, T x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length - 1; i >= index; i--)
            A[i + 1] = A[i]; // Move each element one position to the right
        A[index] = x;
        length++;
    }
}

template <class T>
T Array<T>::Delete(int index)
{
    T x = 0;
    if (index >= 0 && index < length)
    {
        x = A[index];
        for (int i = index; i < length - 1; i++) // Shift elements to the left
            A[i] = A[i + 1];
        length--;
    }
    return x;
}

int main()
{
    Array<char> arr(10); // Create an Array of characters with a size of 10
    arr.Insert(0, 'a');
    arr.Insert(1, 'c');
    arr.Insert(2, 'd');
    arr.Display();

    cout << arr.Delete(0) << endl;
    arr.Display();
    // a c d
    // a
    // c d

    return 0;
}
