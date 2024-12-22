#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue *q, int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (q->front == NULL)
        {
            q->front = q->rear = t;
        }
        else
        {
            q->rear->next = t;
            q->rear = t;
        }
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    struct Node *t;
    if (q->front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        x = q->front->data;
        t = q->front;
        q->front = q->front->next;
        free(t);
    }
    return x;
}

void display(struct Queue *q)
{
    struct Node *p = q->front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct Queue *q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("Queue contents: ");
    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Queue contents after dequeue: ");
    display(q);

    enqueue(q, 40);
    printf("Queue contents after enqueue: ");
    display(q);

    while (q->front != NULL)
    {
        dequeue(q);
    }
    free(q);

    return 0;
}

// Queue contents: 10 20 30
// Dequeued: 10
// Queue contents after dequeue: 20 30
// Queue contents after enqueue: 20 30 40