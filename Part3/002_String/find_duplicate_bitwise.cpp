#include <iostream>
using namespace std;

int main()
{
    char A[] = "finding";
    int bitVector = 0;          // Bit vector to track character occurrences
    bool hasDuplicates = false; // <-- Flag

    for (int i = 0; A[i] != '\0'; i++)
    {
        int index = A[i] - 'a'; // Calculate the index (0 for 'a', 1 for 'b', ..., 25 for 'z')

        if (bitVector & (1 << index))
        {
            cout << "Duplicate character found: " << A[i] << endl;
            hasDuplicates = true;
        }
        else
        {
            bitVector |= (1 << index);
        }
    }

    if (!hasDuplicates)
    {
        cout << "No duplicate characters found." << endl;
    }

    return 0;
}

// Duplicate character found: i
// Duplicate character found: n
