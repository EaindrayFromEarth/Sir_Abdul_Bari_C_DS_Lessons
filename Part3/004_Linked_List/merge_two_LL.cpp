#include <stdio.h>
#include <stdlib.h>

// Sorted Version
struct Node
{
    int data;                                   // Node data
    struct Node *next;                          // Pointer to next node
} *first = NULL, *second = NULL, *third = NULL; // Global pointers for linked lists

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

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for first node
    second->data = A[0];                                 // Set first node's data
    second->next = NULL;                                 // Initialize next pointer to NULL
    last = second;                                       // Set last to first node

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

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last; // Pointer to track the last node in merged list

    // Initialize merged list with the smaller head
    if (p->data < q->data)
    {
        third = last = p;   // Start with p
        p = p->next;        // Move p to next
        third->next = NULL; // Initialize next pointer
    }
    else
    {
        third = last = q;   // Start with q
        q = q->next;        // Move q to next
        third->next = NULL; // Initialize next pointer
    }

    // Merge remaining nodes
    while (p && q)
    {
        if (p->data < q->data)
        {                      // Compare data
            last->next = p;    // Link last to p
            last = p;          // Move last to p
            p = p->next;       // Move p to next
            last->next = NULL; // Initialize next pointer
        }
        else
        {
            last->next = q;    // Link last to q
            last = q;          // Move last to q
            q = q->next;       // Move q to next
            last->next = NULL; // Initialize next pointer
        }
    }

    // Link remaining nodes
    if (p)
        last->next = p; // If p has remaining nodes
    if (q)
        last->next = q; // If q has remaining nodes
}

int main()
{
    int A[] = {10, 20, 40, 50, 60};
    int B[] = {15, 18, 25, 30, 55};

    create(A, 5);
    create2(B, 5);

    Merge(first, second);
    Display(third);

    return 0;
}

// 10 15 18 20 25 30 40 50 55 60