#include <iostream>
#include <cstdlib> // For malloc and free

int main()
{
    int A[5] = {2, 4, 6, 8, 10}; // Static array with 5 elements (uninitialized)

    int *p; // Dynamic array allocated on the heap //C++

    p = (int *)malloc(5 * sizeof(int)); // Dynamic array allocated on the heap //C

    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    std::cout << "Static Array A (uninitialized): ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    // Print the contents of the dynamic array allocated with new
    std::cout << "Dynamic Array P (uninitialized): ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;

    // Deallocate dynamic arrays
    delete[] p;
    free(p);

    // Explanation of static vs dynamic arrays
    std::cout << "Note: Static arrays are allocated on the stack and have a fixed size, while dynamic arrays are allocated on the heap and can be resized. Dynamic arrays require manual memory management." << std::endl;

    // Static Array A (uninitialized): 2 4 6 8 10
    // Dynamic Array P (uninitialized): 3 5 7 9 11
    // free(): double free detected in tcache 2

    return 0;
}
