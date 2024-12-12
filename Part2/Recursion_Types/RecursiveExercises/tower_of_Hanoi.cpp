#include <stdio.h>

/*
 * Tower of Hanoi:
 * The objective of the Tower of Hanoi is to move the entire stack of disks
 * from the source peg (A) to the destination peg (C), using an auxiliary peg (B).
 * The rules are:
 * 1. Only one disk can be moved at a time.
 * 2. Each move consists of taking the upper disk from one of the stacks
 *    and placing it on top of another stack or on an empty peg.
 * 3. No larger disk may be placed on top of a smaller disk.
 *      |          |          |
       ===        ===        ===
      =====      ======      ======
     =======    ========    ========
    |   1   |  |   2   |  |   3   |
    |       |  |       |  |       |

 */

void TOH(int n, int A, int B, int C)
{
    // Time complexity: O(2^n) - exponential time due to recursive calls
    // Space complexity: O(n) - linear space due to the call stack
    if (n > 0)
    {
        TOH(n - 1, A, C, B);       // Move n-1 disks from A to B using C as auxiliary
        printf("(%d, %d) ", A, C); // Move the nth disk from A to C
        TOH(n - 1, B, A, C);       // Move n-1 disks from B to C using A as auxiliary
    }
}

int main()
{
    int n = 3; // Number of disks

    printf("Tower of Hanoi solution for %d disks:\n", n);
    TOH(n, 1, 2, 3); // A=1, B=2, C=3
    printf("\n");    // New line after all moves
    // Tower of Hanoi solution for 3 disks:
    //(1, 3) (1, 2) (3, 2) (1, 3) (2, 1) (2, 3) (1, 3)

    return 0;
}
