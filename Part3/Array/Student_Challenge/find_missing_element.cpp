#include <iostream>
using namespace std;

// Time Complexity: O(n) - Single pass through array
int findMissingElement(int A[], int n)
{
    int diff = A[0] - 0; // Calculate initial difference

    for (int i = 0; i < n; i++)
    {
        if (A[i] - i != diff)
        {                    // Compare current element with expected
            return i + diff; // Calculate missing element's value
        }
    }
    return -1;
}

int main()
{
    int A[] = {6, 7, 8, 9, 13, 14, 15, 16, 17};
    int n = sizeof(A) / sizeof(A[0]);

    int missingElement = findMissingElement(A, n);

    cout << "Missing element: " << missingElement << endl;
    return 0;
}

// Missing element: 10