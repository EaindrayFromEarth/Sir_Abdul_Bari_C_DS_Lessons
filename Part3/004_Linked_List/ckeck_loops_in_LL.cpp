#include <stdio.h>
#include <stdlib.h>

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

int isLoop(struct Node *f)
{
    struct Node *p, *q; // Two pointers for traversal
    p = q = f;          // Initialize both pointers to head

    // Traverse the linked list
    do
    {
        p = p->next;         // Move p one step
        q = q->next;         // Move q one step
        q = q ? q->next : q; // Move q two steps (check for NULL)
    } while (p && q && p != q); // Continue until end or meeting point

    // Check if p and q met
    if (p == q)
        return 1; // Loop detected
    else
        return 0; // No loop
}

int main()
{
    struct Node *t1, *t2;
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    t1 = first->next->next;             // Point to node with data 30
    t2 = first->next->next->next->next; // Point to node with data 50
    t2->next = t1;                      // Create loop by linking last node to node with data 30

    printf("%d\n", isLoop(first));
    return 0;
}

// 1