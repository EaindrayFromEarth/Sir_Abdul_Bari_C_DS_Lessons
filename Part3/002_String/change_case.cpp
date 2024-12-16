#include <iostream>
using namespace std;

int main()
{
    char A[] = "welcome";
    int i;

    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >= 'A' && A[i] <= 'Z')
        {
            A[i] += 32; // Convert uppercase to lowercase
        }
        else if (A[i] >= 'a' && A[i] <= 'z')
        {
            A[i] -= 32; // Convert lowercase to uppercase
        }
    }

    printf("%s\n", A);
    return 0;
}
