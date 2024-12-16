#include <iostream>
using namespace std;

// Time Complexity: O(n) - Single pass through array
// Sorted
void findMultipleMissingElements(int A[], int n)
{
    int diff = A[0] - 0;

    for (int i = 0; i < n; i++)
    {
        // Compare current element with expected
        if (A[i] - i != diff)
        {
            while (diff < A[i] - i)
            {
                cout << i + diff << endl;
                diff++;
            }
        }
    }
}

int main()
{
    int A[] = {6, 7, 8, 9, 12, 15, 16, 17, 18, 19};
    int n = sizeof(A) / sizeof(A[0]);

    findMultipleMissingElements(A, n);

    return 0;
}
// 10
// 11
// 13
// 14
