#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{

    // Variable-Sized array
    int n;
    cout << "Enter Size: ";
    cin >> n;
    int C[n];
    C[0] = 2;

    // Print all elements of C
    for (int i = 0; i < n; i++)
    {
        cout << C[i] << endl; // Outputs elements of C (may show garbage for uninitialized)
    }
    // Expected Output
    //     Enter Size: 7
    // 2
    // 32767  // Output from C[2] (garbage value)
    // -1068958368  // Output from C[3] (garbage value)
    // 22697  // Output from C[4] (garbage value)
    // -887323360  // Output from C[5] (garbage value)
    // 32767  // Output from C[6] (garbage value)
    // -1068968882  // Output from C[7] (garbage value)

    return 0;
} // namespace std
