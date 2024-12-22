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
    q.capacity = 100; // Set a capacity for the queue
    q.front = 0;
    q.rear = 0;
    q.arr = (struct Node **)malloc(q.capacity * sizeof(struct Node *));

    printf("Enter root value: ");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL; // Initialize children to NULL
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
            t->lchild = t->rchild = NULL; // Initialize children to NULL
            p->lchild = t;
            enqueue(&q, t);
        }

        printf("Enter right child of %d (-1 for no child): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL; // Initialize children to NULL
            p->rchild = t;
            enqueue(&q, t);
        }
    }

    free(q.arr); // Free the queue array
}

void preorder(struct Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preorder(node->lchild);
    preorder(node->rchild);
}

void inorder(struct Node *node)
{
    if (node == NULL)
        return;
    inorder(node->lchild);
    printf("%d ", node->data);
    inorder(node->rchild);
}

void postorder(struct Node *node)
{
    if (node == NULL)
        return;
    postorder(node->lchild);
    postorder(node->rchild);
    printf("%d ", node->data);
}

int main()
{
    create();

    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}

// Enter root value: 3
// Enter left child of 3 (-1 for no child): 2
// Enter right child of 3 (-1 for no child): 1
// Enter left child of 2 (-1 for no child): 1
// Enter right child of 2 (-1 for no child): -1
// Enter left child of 1 (-1 for no child): 1
// Enter right child of 1 (-1 for no child): -1
// Enter left child of 1 (-1 for no child): -1
// Enter right child of 1 (-1 for no child): -1
// Enter left child of 1 (-1 for no child): -1
// Enter right child of 1 (-1 for no child): -1

// Preorder Traversal: 3 2 1 1 1
// Inorder Traversal: 1 2 3 1 1
// Postorder Traversal: 1 2 1 1 3