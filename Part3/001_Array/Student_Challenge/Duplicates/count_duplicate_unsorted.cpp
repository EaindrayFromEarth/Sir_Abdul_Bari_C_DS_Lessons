#include <iostream>
using namespace std;

// O(n^2)
void countDuplicatesInUnsorted(int A[], int n)
{
    bool counted[n] = {false};

    for (int i = 0; i < n - 1; i++)
    {
        if (counted[i])
            continue; // Skip if already counted

        int count = 1;
        // Check for duplicates starting from the next element
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] == A[j])
            {
                count++;
                counted[j] = true; // Mark the duplicate element as counted
            }
        }
        if (count > 1)
        {
            cout << A[i] << " appears " << count << " times" << endl;
        }
    }
}

int main()
{
    int A[] = {3, 1, 2, 3, 2, 4, 5, 1};
    int n = sizeof(A) / sizeof(A[0]);

    countDuplicatesInUnsorted(A, n);
    return 0;
}

// 3 appears 2 times
// 1 appears 2 times
// 2 appears 2 times