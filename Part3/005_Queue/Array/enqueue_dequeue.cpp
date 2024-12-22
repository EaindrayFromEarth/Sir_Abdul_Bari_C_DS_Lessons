#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
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
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    int i;
    for (i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    printf("Enter size: ");
    scanf("%d", &q.size);

    q.Q = (int *)malloc(q.size * sizeof(int));
    q.front = q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 40);
    Display(q);

    printf("Dequeued: %d\n", dequeue(&q));
    Display(q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q)); // This will show "Queue is empty"

    // Free allocated memory
    free(q.Q);

    return 0;
}

// Enter size: 4
// 10 20 40
// Dequeued: 10
// 20 40
// Dequeued: 20
// Dequeued: 40
// Queue is empty
// Dequeued: -1