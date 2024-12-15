#include <iostream>
using namespace std;

// O(n)
void findDuplicatesSorted(int A[], int n)
{
    int lastDuplicate = 0; // Track last printed duplicate

    for (int i = 0; i < n - 1; i++)
    {
        // Check if current and next elements are the same
        if (A[i] == A[i + 1] && A[i] != lastDuplicate)
        {
            cout << A[i] << endl;
            lastDuplicate = A[i];
        }
    }
}

int main()
{
    int A[] = {1, 2, 2, 3, 3, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);

    findDuplicatesSorted(A, n);

    // Time Complexity: O(n) - Single pass through array
    return 0;
}

// 2 3