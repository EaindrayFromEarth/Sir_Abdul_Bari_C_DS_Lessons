#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[3][4] = {
        {1, 2, 3, 4},
        {2, 4, 6, 8},
        {1, 3, 5, 7}};

    int *B[3];
    int **C;
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    B[0] = (int *)malloc(4 * sizeof(int));
    B[1] = (int *)malloc(4 * sizeof(int));
    B[2] = (int *)malloc(4 * sizeof(int));

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    C = (int **)malloc(3 * sizeof(int *));
    C[0] = (int *)malloc(4 * sizeof(int));
    C[1] = (int *)malloc(4 * sizeof(int));
    C[2] = (int *)malloc(4 * sizeof(int));

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", &C[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    free(C);

    return 0;
}

// 1 2 3 4
// 2 4 6 8
// 1 3 5 7
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0
// -578574544 -578574540 -578574536 -578574532
// -578574512 -578574508 -578574504 -578574500
// -578574480 -578574476 -578574472 -578574468
// 0 0 0 0
// 0 0 0 0
// 0 0 0 0