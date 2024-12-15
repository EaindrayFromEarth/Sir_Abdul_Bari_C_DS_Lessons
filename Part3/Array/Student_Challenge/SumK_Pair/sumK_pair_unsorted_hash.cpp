#include <iostream>
#include <unordered_map>
using namespace std;

// O(n)
void findSumKPairsUnsorted(int A[], int n, int k)
{
    unordered_map<int, int> H;

    for (int i = 0; i < n; i++)
    {
        int complement = k - A[i];

        if (H[complement] > 0)
        {
            cout << A[i] << " + " << complement << " = " << k << endl;
        }

        H[A[i]]++;
    }
}

int main()
{
    int A[] = {3, 1, 2, 4, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 7;

    findSumKPairsUnsorted(A, n, k);
    return 0;
}
