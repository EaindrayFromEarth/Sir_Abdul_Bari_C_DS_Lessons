#include <iostream>
#include <cstring>
using namespace std;

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void Perm(char S[], int l, int h)
{
    if (l == h)
    {
        cout << S << endl;
    }
    else
    {
        for (int i = l; i <= h; i++)
        {
            swap(S[l], S[i]);  // <--- Swap the current index with the start index
            Perm(S, l + 1, h); // <--- Recur for the next index
            swap(S[l], S[i]);  // <--- Backtrack to restore the original string
        }
    }
}

int main()
{
    char S[] = "abc";
    int n = strlen(S);
    cout << "Permutations of " << S << " are:" << endl;
    Perm(S, 0, n - 1);
    return 0;
}

// Permutations of abc are:
// abc
// acb
// bac
// bca
// cab
// cba
