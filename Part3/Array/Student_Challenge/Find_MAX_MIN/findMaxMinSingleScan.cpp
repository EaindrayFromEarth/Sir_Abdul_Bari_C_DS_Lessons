#include <iostream>
using namespace std;

// O(n)
void findMinMax(int A[], int n)
{
    if (n <= 0)
        return;

    int min = A[0];
    int max = A[0];

    for (int i = 1; i < n; i++)
    {
        if (A[i] < min)
        {
            min = A[i]; // Update min if current element is smaller
        }
        else if (A[i] > max)
        {
            max = A[i]; // Update max if current element is larger
        }
    }

    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;
}

int main()
{
    int A[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = sizeof(A) / sizeof(A[0]);

    findMinMax(A, n);
    return 0;
}
