#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int count(struct Node *p)
{
    int cnt = 0;
    while (p != NULL)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

// Reverse linked list using array (method 1)
// Time Complexity: O(n) for creating array + O(n) for copying back = O(n)
void Reverse1(struct Node *p)
{
    int *A, i = 0;      // Array to hold node data
    struct Node *q = p; // Pointer for traversal

    // Allocate memory for array
    A = (int *)malloc(sizeof(int) * count(p)); // Use the count function

    // Store node data in array
    while (q != NULL)
    {
        A[i] = q->data; // Save data
        q = q->next;    // Move to next node
        i++;            // Increment index
    }

    q = p; // Reset pointer to head
    i--;   // Set index to last element

    // Copy data back to linked list in reverse order
    while (q != NULL)
    {
        q->data = A[i]; // Assign reversed data
        q = q->next;    // Move to next node
        i--;
    }

    free(A); // Free allocated memory for array
}

// Reverse linked list using iterative method (method 2)
// Time Complexity: O(n)
void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL; // Pointers for reversal

    // Iterate through the linked list
    while (p != NULL)
    {
        r = q;       // Store previous node
        q = p;       // Current node becomes previous
        p = p->next; // Move to next node
        q->next = r; // Reverse the link
    }
    first = q; // Update head to new first node
}

// Reverse linked list using recursion (method 3)
// Time Complexity: O(n)
void Reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        Reverse3(p, p->next); // Recursive call
        p->next = q;          // Reverse the link
    }
    else
    {
        first = q; // Update head to new first node
    }
}

int main()
{
    int A[] = {10, 20, 40, 50, 60};
    create(A, 5);

    // Reverse1(first); // method 1
    // Reverse2(first); // method 2
    Reverse3(NULL, first); // method 3, pass NULL as the first argument

    Display(first);

    // Comparing on performance:
    // Method 1 (Reverse1) is generally the slowest because it requires O(n) space
    // for the array and O(n) time to copy the data back, resulting in O(n) time complexity.

    // Method 2 (Reverse2) (iterative) is the Fastest in terms of time complexity and space usage.
    // It operates in O(n) time and O(1) space, as it only uses a few pointers for reversal.

    // Method 3 (Reverse3) also has O(n) time complexity but uses O(n) space on the call stack
    // due to recursion. This can lead to stack overflow for very large lists.

    // In summary, for large linked lists, Method 2 (iterative) is the most efficient.

    return 0;
}
