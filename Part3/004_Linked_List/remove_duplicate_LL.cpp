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

void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next; // Start with the second node

    // Traverse the linked list
    while (q != NULL)
    {
        if (p->data != q->data)
        {                // Check if current and next data are different
            p = q;       // Move p to current node
            q = q->next; // Move q to next node
        }
        else
        {
            p->next = q->next; // Link p to the next unique node
            free(q);           // Free memory of duplicate node
            q = p->next;       // Move q to the next node
        }
    }
}

int main()
{
    int A[] = {10, 20, 20, 40, 50, 50, 50, 60};
    create(A, 8);
    Display(first);
    printf("\n");

    RemoveDuplicate(first);
    Display(first);

    return 0;
}

// 10 20 20 40 50 50 50 60
// 10 20 40 50 60