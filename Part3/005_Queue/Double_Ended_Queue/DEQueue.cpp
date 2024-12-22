/*
Queue Operations:
-----------------
Insert (front x, rear /)
Delete (front /, rear x)

DEQueue Operations:
-------------------
Insert (front /, rear /)
Delete (front /, rear /)
*/

// 2 types of Restricted DEQueue
// Input Restricted DEQueue (insert is only allowed by Rear)
// and Output Restricted DEQueue (delete is only allowed by Front)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Deque
{
    struct Node *front;
    struct Node *rear;
};

struct Deque *createDeque()
{
    struct Deque *dq = (struct Deque *)malloc(sizeof(struct Deque));
    dq->front = dq->rear = NULL;
    return dq;
}

void insertRear(struct Deque *dq, int data)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->next = NULL;
    t->prev = dq->rear;

    if (dq->rear == NULL)
    {
        dq->front = dq->rear = t;
    }
    else
    {
        dq->rear->next = t;
        dq->rear = t;
    }
}

int deleteFront(struct Deque *dq)
{
    if (dq->front == NULL)
    {
        printf("Deque is empty\n");
        return -1;
    }
    struct Node *t = dq->front;
    int data = t->data;
    dq->front = dq->front->next;
    if (dq->front != NULL)
    {
        dq->front->prev = NULL;
    }
    else
    {
        dq->rear = NULL;
    }
    free(t);
    return data;
}

int deleteRear(struct Deque *dq)
{
    if (dq->rear == NULL)
    {
        printf("Deque is empty\n");
        return -1;
    }
    struct Node *t = dq->rear;
    int data = t->data;
    dq->rear = dq->rear->prev;
    if (dq->rear != NULL)
    {
        dq->rear->next = NULL;
    }
    else
    {
        dq->front = NULL;
    }
    free(t);
    return data;
}

void display(struct Deque *dq)
{
    struct Node *current = dq->front;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void demonstrateInputRestrictedDeque()
{
    struct Deque *dq = createDeque();

    insertRear(dq, 10);
    insertRear(dq, 20);
    insertRear(dq, 30);
    printf("Input Restricted Deque contents: ");
    display(dq);

    printf("Deleted from front: %d\n", deleteFront(dq));
    printf("Input Restricted Deque contents after deleting from front: ");
    display(dq);

    printf("Deleted from rear: %d\n", deleteRear(dq));
    printf("Input Restricted Deque contents after deleting from rear: ");
    display(dq);

    while (dq->front != NULL)
    {
        deleteFront(dq);
    }
    free(dq);
}

void demonstrateOutputRestrictedDeque()
{
    struct Deque *dq = createDeque();

    insertRear(dq, 10);
    insertRear(dq, 20);
    insertRear(dq, 30);
    printf("Output Restricted Deque contents: ");
    display(dq);

    printf("Deleted from front: %d\n", deleteFront(dq));
    printf("Output Restricted Deque contents after deleting from front: ");
    display(dq);

    insertRear(dq, 40);
    insertRear(dq, 50);
    printf("Output Restricted Deque contents after inserting at rear: ");
    display(dq);

    while (dq->front != NULL)
    {
        deleteFront(dq);
    }
    free(dq);
}

int main()
{
    printf("Demonstrating Input Restricted Deque:\n");
    demonstrateInputRestrictedDeque();

    printf("\nDemonstrating Output Restricted Deque:\n");
    demonstrateOutputRestrictedDeque();

    return 0;
}

// Demonstrating Input Restricted Deque:
// Input Restricted Deque contents: 10 20 30
// Deleted from front: 10
// Input Restricted Deque contents after deleting from front: 20 30
// Deleted from rear: 30
// Input Restricted Deque contents after deleting from rear: 20

// Demonstrating Output Restricted Deque:
// Output Restricted Deque contents: 10 20 30
// Deleted from front: 10
// Output Restricted Deque contents after deleting from front: 20 30
// Output Restricted Deque contents after inserting at rear: 20 30 40 50