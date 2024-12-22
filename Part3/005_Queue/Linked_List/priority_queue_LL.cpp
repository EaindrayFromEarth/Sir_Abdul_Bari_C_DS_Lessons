#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct PriorityQueue
{
    struct Node *front;
};

struct PriorityQueue *createPriorityQueue()
{
    struct PriorityQueue *pq = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
    pq->front = NULL;
    return pq;
}

void insert(struct PriorityQueue *pq, int data, int priority)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = data;
    t->priority = priority;
    t->next = NULL;

    if (pq->front == NULL || pq->front->priority > priority)
    {
        t->next = pq->front;
        pq->front = t;
    }
    else
    {
        struct Node *current = pq->front;
        while (current->next != NULL && current->next->priority <= priority)
        {
            current = current->next;
        }
        t->next = current->next;
        current->next = t;
    }
}

int deleteMaxPriority(struct PriorityQueue *pq)
{
    if (pq->front == NULL)
    {
        printf("Priority Queue is empty\n");
        return -1;
    }
    struct Node *t = pq->front;
    int data = t->data;
    pq->front = pq->front->next;
    free(t);
    return data;
}

void display(struct PriorityQueue *pq)
{
    struct Node *current = pq->front;
    while (current)
    {
        printf("Data: %d, Priority: %d\n", current->data, current->priority);
        current = current->next;
    }
}

int main()
{
    struct PriorityQueue *pq = createPriorityQueue();

    insert(pq, 'A', 1);
    insert(pq, 'B', 1);
    insert(pq, 'C', 2);
    insert(pq, 'D', 3);
    insert(pq, 'E', 2);

    printf("Priority Queue contents:\n");
    display(pq);

    printf("Deleted element with highest priority: %c\n", deleteMaxPriority(pq));
    printf("Priority Queue contents after deletion:\n");
    display(pq);

    while (pq->front != NULL)
    {
        deleteMaxPriority(pq);
    }
    free(pq);

    return 0;
}

// Priority Queue contents:
// Data: 65, Priority: 1
// Data: 66, Priority: 1
// Data: 67, Priority: 2
// Data: 69, Priority: 2
// Data: 68, Priority: 3
// Deleted element with highest priority: A
// Priority Queue contents after deletion:
// Data: 66, Priority: 1
// Data: 67, Priority: 2
// Data: 69, Priority: 2
// Data: 68, Priority: 3