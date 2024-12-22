#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    int i = (q.front + 1) % q.size;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    printf("\n");
}

int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Queue contents: ");
    Display(q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Queue contents after dequeue: ");
    Display(q);

    enqueue(&q, 40);
    enqueue(&q, 50);
    printf("Queue contents after enqueue: ");
    Display(q);

    enqueue(&q, 60); // This should show "Queue is full"

    free(q.Q);

    return 0;
}

// Queue contents: 10 20 30
// Dequeued: 10
// Queue contents after dequeue: 20 30
// Queue contents after enqueue: 20 30 40 50
// Queue is full