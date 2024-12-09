#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    // pointers: address of data, not the data itself
    // Access the data indirectly (from Heap)
    // Access the resources outside the program (keyboard, monitor, etc.)
    // For parameter passing

    // program can only access code section and Stack
    // Can't directly access the heap (because heap is outside the program)

    int a = 10; // Data variable
    int *p;     // Address variable (pointer)
    p = &a;     // Assign the address of 'a' to pointer 'p'

    cout << a << endl;                                    // Outputs: 10
    printf("Value accessed through pointer p: %d\n", *p); // Outputs: 10

    printf("Address of a: %p\n", (void *)&a);               // Outputs the address of 'a'
    printf("Address stored in pointer p: %p\n", (void *)p); // Outputs the address of 'a'

    // Output
    //  Value of a: 10
    //  Value accessed through pointer p: 10
    //  Address of a: 0x7ffe468ede7c
    //  Address stored in pointer p: 0x7ffe468ede7c

    // int A[5] = {2, 4, 6, 8, 10};
    // int *p1;
    // p1 = A;

    // for (int i = 0; i < 5; i++) {
    //     cout << p1[i] << endl;
    // } //2, 4, 6, 8, 10
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    int *p1;
    // Dynamic memory allocation using malloc
    // malloc is used to allocate a block of memory on the heap.
    // It returns a pointer to the beginning of the allocated memory.
    p1 = (int *)malloc(5 * sizeof(int));
    p1[0] = 10;
    p1[1] = 15;
    p1[2] = 14;
    p1[3] = 21;
    p1[4] = 31;

    for (int i = 0; i < 5; i++)
    {
        cout << p1[i] << endl;
    } // 10, 15 ,14,21, 31

    free(p1); // Free the allocated memory to prevent memory leaks

    // Every pointer take the same amount of memory
    int *p2;
    char *p3;
    float *p4;
    double *p5;
    struct Rectangle *p6;
    cout << sizeof(p2) << endl; // 8
    cout << sizeof(p3) << endl; // 8
    cout << sizeof(p4) << endl; // 8
    cout << sizeof(p5) << endl; // 8
    cout << sizeof(p6) << endl; // 8
    return 0;
}
