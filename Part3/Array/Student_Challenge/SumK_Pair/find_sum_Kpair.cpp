#include <iostream>
using namespace std;

// O(n^2)
void findSumKPairs(int A[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Check if the sum of the pair equals k
            if (A[i] + A[j] == k)
            {
                cout << A[i] << " + " << A[j] << " = " << k << endl;
            }
        }
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 7; // Target sum

    findSumKPairs(A, n, k);
    return 0;
}

// 1 + 6 = 7
// 2 + 5 = 7
// 3 + 4 = 7
