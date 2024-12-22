#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Queue
{
    struct Node **arr;
    int front;
    int rear;
    int capacity;
};

void createQueue(struct Queue *q, int capacity)
{
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->arr = (struct Node **)malloc(q->capacity * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *node)
{
    q->arr[q->rear] = node;
    q->rear++;
}

struct Node *dequeue(struct Queue *q)
{
    struct Node *node = q->arr[q->front];
    q->front++;
    return node;
}

int isEmpty(struct Queue *q)
{
    return q->front == q->rear;
}

struct Node *root = NULL;

void create()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    createQueue(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(&q))
    {
        p = dequeue(&q);

        printf("Enter left child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter right child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }

    free(q.arr);
}

void LevelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    struct Queue q;
    createQueue(&q, 100);
    printf("%d ", root->data);
    enqueue(&q, root);

    while (!isEmpty(&q))
    {
        root = dequeue(&q);

        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }

        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }

    free(q.arr);
}

int main()
{
    create();

    printf("Level Order Traversal: ");
    LevelOrder(root);
    printf("\n");

    return 0;
}

// Enter root value: 5
// Enter left child of 5 (-1 for no child): 3
// Enter right child of 5 (-1 for no child): 8
// Enter left child of 3 (-1 for no child): -1
// Enter right child of 3 (-1 for no child): 4
// Enter left child of 8 (-1 for no child): 6
// Enter right child of 8 (-1 for no child): 9
// Enter left child of 4 (-1 for no child): -1
// Enter right child of 4 (-1 for no child): -1
// Enter left child of 6 (-1 for no child): -1
// Enter right child of 6 (-1 for no child): -1
// Enter left child of 9 (-1 for no child): -1
// Enter right child of 9 (-1 for no child): -1
// Level Order Traversal: 5 3 8 4 6 9