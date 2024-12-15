#include <iostream>
#include <unordered_map>
using namespace std;

// Time Complexity: O(n)
void countDuplicatesUsingHashTable(int A[], int n)
{
    unordered_map<int, int> H; // Create a hash table

    // Populate the hash table with element counts
    for (int i = 0; i < n; i++)
    {
        H[A[i]]++;
    }

    for (const auto &pair : H)
    {
        if (pair.second > 1)
        { // Check if count is greater than 1
            cout << pair.first << " is appearing " << pair.second << " times" << endl;
        }
    }
}

int main()
{
    int A[] = {1, 2, 2, 3, 3, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);

    countDuplicatesUsingHashTable(A, n);

    return 0;
}

// 3 is appearing 3 times
// 2 is appearing 2 times