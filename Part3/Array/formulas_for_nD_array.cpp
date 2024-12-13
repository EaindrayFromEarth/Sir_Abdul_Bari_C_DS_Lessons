
#include <stdio.h>

int main()
{
    int A[2][3][4] = {
        {{1, 2, 3, 4},
         {5, 6, 7, 8},
         {9, 10, 11, 12}},
        {{13, 14, 15, 16},
         {17, 18, 19, 20},
         {21, 22, 23, 24}}};

    int L0 = 1000;       // Example base address
    int w = sizeof(int); // Size of each element in bytes (4 for int)

    // Row-Major Order Address Calculation Formula for nD Arrays:
    // Address(A[i1][i2][...][ik]) = L0 + (i1 * n2 * n3 * ... * nk + i2 * n3 * ... * nk + ... + ik) * w
    // where n2, n3, ..., nk are the sizes of the subsequent dimensions

    // Column-Major Order Address Calculation Formula for nD Arrays:
    // Address(A[i1][i2][...][ik]) = L0 + (i2 * n1 * n3 * ... * nk + i3 * n1 * n2 * ... * nk + ... + ik) * w
    // where n1, n2, ..., nk are the sizes of the dimensions

    int i1 = 1;
    int i2 = 2;
    int i3 = 3;

    int n1 = 2;
    int n2 = 3;
    int n3 = 4;

    int address_row_major = L0 + (i1 * n2 * n3 + i2 * n3 + i3) * w;
    printf("Address of A[1][2][3] in Row-Major Order: %d\n", address_row_major);

    int address_column_major = L0 + (i2 * n1 * n3 + i3 * n1 * n2 + i1) * w;
    printf("Address of A[1][2][3] in Column-Major Order: %d\n", address_column_major);

    // Address of A[1][2][3] in Row-Major Order: 1092
    // Address of A[1][2][3] in Column-Major Order: 1140

    return 0;
}
