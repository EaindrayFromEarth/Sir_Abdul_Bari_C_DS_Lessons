#include <iostream>
#include <unordered_map>
using namespace std;

// O(n)
void findSumKPairs(int A[], int n, int k)
{
    unordered_map<int, int> H;
    for (int i = 0; i < n; i++)
    {
        H[A[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        int complement = k - A[i];

        // Check if the complement exists in the hash table
        if (H[complement] > 0)
        {
            cout << A[i] << " + " << complement << " = " << k << endl;

            // Decrement the count of the current element and its complement
            H[A[i]]--;
            H[complement]--;
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
