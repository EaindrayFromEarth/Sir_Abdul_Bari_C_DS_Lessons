#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main()
{
    int *p, *q;
    int i;

    p = (int *)malloc(5 * sizeof(int));
    if (p == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;

    printf("Dynamic Array P: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");

    q = (int *)malloc(10 * sizeof(int)); // New array with increased size
    if (q == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        free(p); // Free the old array before exiting
        return 1;
    }

    // Copy contents from old array to new array
    for (i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }

    for (i = 5; i < 10; i++)
    {
        q[i] = 0;
    }

    free(p);
    p = q;
    q = NULL;
    printf("Dynamic Array P after resizing: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    // Dynamic Array P: 3 5 7 9 11
    // Dynamic Array P after resizing: 3 5 7 9 11 0 0 0 0 0

    free(p);

    return 0;
}
