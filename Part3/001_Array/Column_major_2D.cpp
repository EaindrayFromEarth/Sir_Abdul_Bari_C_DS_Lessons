#include <stdio.h>

int main()
{
    int A[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    // Base address of the array (for example purposes)
    int L0 = 1000;       // Example base address
    int w = sizeof(int); // Size of each element in bytes (4 for int)

    // Row-Major Order Address Calculation Formula:
    // Address(A[i][j]) = L0 + (i * n + j) * w
    // where n = number of columns

    // Column-Major Order Address Calculation Formula:
    // Address(A[i][j]) = L0 + (j * m + i) * w
    // where m = number of rows

    // Row-major order address calculation
    int i = 2;
    int j = 3;
    int n = 4;

    int address_row_major = L0 + (i * n + j) * w;
    printf("Address of A[2][3] in Row-Major Order: %d\n", address_row_major);

    // Column-major order address calculation
    int m = 3;

    int address_column_major = L0 + (j * m + i) * w;
    printf("Address of A[2][3] in Column-Major Order: %d\n", address_column_major);

    // Address of A[2][3] in Row-Major Order: 1044
    // Address of A[2][3] in Column-Major Order: 1044

    return 0;
}
