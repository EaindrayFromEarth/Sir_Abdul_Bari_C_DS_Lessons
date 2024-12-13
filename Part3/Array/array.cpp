#include <stdio.h>

int main()
{
    // Different types of Array Declaration
    int A[5];                   // Array A with 5 elements (uninitialized)
    int B[5] = {0};             // Array B initialized with 0s
    int C[5] = {1, 2};          // Array C partially initialized (remaining elements are garbage)
    int D[5] = {0, 1, 2, 3, 4}; // Array D fully initialized
    int E[5] = {5, 6, 7};       // Array E partially initialized (remaining elements are garbage)

    // Print the contents of each array
    printf("Array A (uninitialized): ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", &A[i]); // May contain garbage values
    }
    printf("\n");

    printf("Array B (initialized to 0): ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", B[i]); // All elements are 0
    }
    printf("\n");

    printf("Array C (partially initialized): ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", C[i]); // First two elements are 1 and 2, others are garbage
    }
    printf("\n");

    printf("Array D (fully initialized): ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", D[i]); // All elements are initialized
    }
    printf("\n");

    printf("Array E (partially initialized): ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", E[i]); // First three elements are 5, 6, 7, others are garbage
    }
    printf("\n");

    // Explanation of Array A's output
    printf("Note: The values in Array A increment by 4 because each integer typically occupies 4 bytes in memory.\n");

    // Array A (uninitialized): 885451488 885451492 885451496 885451500 885451504
    // Array B (initialized to 0): 0 0 0 0 0
    // Array C (partially initialized): 1 2 0 0 0
    // Array D (fully initialized): 0 1 2 3 4
    // Array E (partially initialized): 5 6 7 0 0
    return 0;
}
