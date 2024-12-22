#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}

void countNodes(struct Node *p, int *leafCount, int *nonLeafCount)
{
    if (p == NULL)
        return;

    if (!p->lchild && !p->rchild)
    {
        (*leafCount)++;
    }
    else
    {
        (*nonLeafCount)++;
    }

    countNodes(p->lchild, leafCount, nonLeafCount);
    countNodes(p->rchild, leafCount, nonLeafCount);
}

int main()
{
    // Example tree creation
    struct Node *root = createNode(1);
    root->lchild = createNode(2);
    root->rchild = createNode(3);
    root->lchild->lchild = createNode(4);
    root->lchild->rchild = createNode(5);
    root->rchild->lchild = createNode(6);

    int leafCount = 0;
    int nonLeafCount = 0;

    countNodes(root, &leafCount, &nonLeafCount);

    printf("Leaf nodes: %d\n", leafCount);
    printf("Non-leaf nodes: %d\n", nonLeafCount);

    return 0;
}

// Expected output:
// Leaf nodes: 3
// Non-leaf nodes: 3