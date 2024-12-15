#include <iostream>
#include <unordered_map>
using namespace std;

// Time Complexity: O(n) - Two passes through array
// Unsorted
// if you have an issue with memory space, don't use Hash Table
void findMissingInUnsorted(int A[], int n)
{
    unordered_map<int, int> H;

    // Populate hash table with array elements
    for (int i = 0; i < n; i++)
    {
        H[A[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (H[i] == 0)
        { //  If the element is not in the hash table
            cout << i << endl;
        }
    }
}

int main()
{
    int A[] = {3, 7, 1, 2, 8, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);

    findMissingInUnsorted(A, n);

    return 0;
}
