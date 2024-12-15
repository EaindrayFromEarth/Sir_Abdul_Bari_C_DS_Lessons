#include <iostream>
using namespace std;

// Time Complexity: O(n)
void countDuplicatesSorted(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // Check if current and next elements are the same
        if (A[i] == A[i + 1])
        {
            int j = i + 1; // <-- Start counting duplicates
            // Count all occurrences of the duplicate
            while (j < n && A[j] == A[i])
            {
                j++;
            }
            cout << A[i] << " is appearing " << (j - i) << " times" << endl;
            i = j - 1; // Move index back to last counted duplicate
        }
    }
}

int main()
{
    int A[] = {1, 2, 2, 3, 3, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);

    countDuplicatesSorted(A, n);

    return 0;
}

// 2 is appearing 2 times
// 3 is appearing 3 times