#include <iostream>
#include <algorithm>
using namespace std;

// O(n^2) for the sorting, O(n) for the two-pointer approach
// O(nlogn) for Time Complexity
void findSumKPairs(int A[], int n, int k)
{
    sort(A, A + n);

    int i = 0;
    int j = n - 1;

    // Use two pointers to find pairs
    while (i < j)
    {
        if (A[i] + A[j] == k)
        {
            printf("%d + %d = %d\n", A[i], A[j], k);
            i++;
            j--;
        }
        else if (A[i] + A[j] < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

int main()
{
    int A[] = {3, 1, 2, 4, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 7;

    findSumKPairs(A, n, k);
    return 0;
}

// 1 + 6 = 7
// 2 + 5 = 7
// 3 + 4 = 7
