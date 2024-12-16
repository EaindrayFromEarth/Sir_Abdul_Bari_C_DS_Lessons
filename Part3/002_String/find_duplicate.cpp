#include <iostream>
#include <cstdio>
using namespace std;

// O(n)
int main()
{
    char A[] = "finding";
    int H[26] = {0};
    int i;

    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 'a'] += 1;
    }

    // Print duplicate characters
    cout << "Duplicate characters: ";
    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            printf("%c ", i + 'a');
        }
    }
    cout << endl;

    printf("Count of 'i': %d\n", H['i' - 'a']);

    return 0;
}

// Duplicate characters: i n
// Count of 'i': 1
