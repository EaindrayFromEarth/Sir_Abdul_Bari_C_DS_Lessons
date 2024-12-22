#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *arr;
    int top;
    int capacity;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int x)
{
    stack->arr[++stack->top] = x;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

struct Queue
{
    struct Stack *s1;
    struct Stack *s2;
};

struct Queue *createQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->s1 = createStack(capacity);
    queue->s2 = createStack(capacity);
    return queue;
}

void enqueue(struct Queue *queue, int x)
{
    push(queue->s1, x);
}

int dequeue(struct Queue *queue)
{
    int x = -1;
    if (isEmpty(queue->s2))
    {
        if (isEmpty(queue->s1))
        {
            printf("Queue Empty\n");
            return x;
        }
        else
        {
            while (!isEmpty(queue->s1))
            {
                push(queue->s2, pop(queue->s1));
            }
        }
    }
    return pop(queue->s2);
}

void freeQueue(struct Queue *queue)
{
    free(queue->s1->arr);
    free(queue->s1);
    free(queue->s2->arr);
    free(queue->s2);
    free(queue);
}

int main()
{
    struct Queue *queue = createQueue(100);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue)); // This should indicate that the queue is empty

    freeQueue(queue);
    return 0;
}

// Dequeued: 10
// Dequeued: 20
// Dequeued: 30
// Queue Empty
// Dequeued: -1