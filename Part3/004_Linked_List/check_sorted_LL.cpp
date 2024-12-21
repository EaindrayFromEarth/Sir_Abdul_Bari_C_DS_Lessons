#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;          // Node data
    struct Node *next; // Pointer to next node
} *first = NULL, *second = NULL, *third = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for first node
    first->data = A[0];                                 // Set first node's data
    first->next = NULL;                                 // Initialize next pointer to NULL
    last = first;                                       // Set last to first node

    // Loop through array to create nodes
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node)); // Allocate new node
        t->data = A[i];                                 // Set new node's data
        t->next = NULL;                                 // Initialize next pointer to NULL
        last->next = t;                                 // Link last node to new node
        last = t;                                       // Update last to new node
    }
}

int isSorted(struct Node *p)
{
    int x = -65536; // Start with a very low value

    // Traverse linked list to check order
    while (p != NULL)
    {
        if (p->data < x) // Compare current data with previous
            return 0;    // Return 0 if not sorted
        x = p->data;     // Update x to current data
        p = p->next;     // Move to next node
    }
    return 1; // Return 1 if sorted
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    printf("%d\n", isSorted(first)); // Check if linked list is sorted
    return 0;
}

// 1