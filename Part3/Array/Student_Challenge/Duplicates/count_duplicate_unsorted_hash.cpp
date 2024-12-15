#include <iostream>
#include <unordered_map>
using namespace std;

// O(n)
void countDuplicatesInUnsorted(int A[], int n)
{
    unordered_map<int, int> H;

    // Populate the hash table with element counts
    for (int i = 0; i < n; i++)
    {
        H[A[i]]++;
    }

    // Iterate through the hash table to print duplicates
    for (const auto &pair : H)
    {
        if (pair.second > 1)
        { // Check if count is greater than 1
            cout << pair.first << " appears " << pair.second << " times" << endl;
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

// 2 appears 2 times
// 1 appears 2 times
// 3 appears 2 times
