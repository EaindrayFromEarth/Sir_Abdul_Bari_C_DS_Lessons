#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char A[] = "decimal";
    char B[] = "medical";
    int i, H[26] = {0};

    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 'a'] += 1; // Increment the count for the character
    }

    // Decrease the count for each character in string B
    for (i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 'a'] -= 1;
        if (H[B[i] - 'a'] < 0)
        { // If count goes negative, not an anagram
            cout << "Not an Anagram" << endl;
            return 0;
        }
    }

    cout << "It's an Anagram" << endl;

    return 0;
}
