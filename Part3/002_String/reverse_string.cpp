#include <iostream>
using namespace std;

int main()
{
    char A[] = "python";
    // char B[7];
    int i = 0, j;

    while (A[i] != '\0')
    {
        i++;
    }

    // Set j to the last index of A
    j = i - 1;

    // Reverse the string using a single loop
    for (int k = 0; k < i / 2; k++)
    {
        char t = A[k];
        A[k] = A[j];
        A[j] = t;
        j--; // Move backwards in A
    }

    cout << "Reversed string: " << A << endl;

    return 0;
}
