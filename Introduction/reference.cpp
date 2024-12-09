#include <iostream>

using namespace std;

int main()
{
    // Reference variables: an alias for another variable
    // They allow you to access the original variable directly
    // References can't be changed to refer to another variable

    int a = 10;   // Data variable
    int &ref = a; // Reference variable 'ref' is an alias for 'a' (like a second name)

    cout << "Initial value of a: " << a << endl;                     //  10
    cout << "Value accessed through reference ref: " << ref << endl; //  10

    ref = 20;

    cout << "Value of a after modifying ref: " << a << endl;                            //  20
    cout << "Value accessed through reference ref after modification: " << ref << endl; //  20

    // Output
    //  Value of a: 10
    //  Value accessed through reference ref: 10
    //  After modifying ref:
    //  Value of a: 20
    //  Value accessed through reference ref: 20

    // Reference variables can also be used with arrays
    int arr[5] = {2, 4, 6, 8, 10};
    cout << "Array elements accessed through references:" << endl;
    for (int i = 0; i < 5; i++)
    {
        int &refArr = arr[i];   // Reference to each element in the array
        cout << refArr << endl; // Outputs: 2, 4, 6, 8, 10
    }

    return 0;
}
