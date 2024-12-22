#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} Node;

Node *RSearch(Node *t, int key)
{
    if (t == NULL)
        return NULL;
    if (key == t->data)
        return t;
    else if (key < t->data)
        return RSearch(t->lchild, key);
    else
        return RSearch(t->rchild, key);
}

void Insert(Node **root, int key)
{
    Node *r = NULL, *t = *root;
    while (t != NULL)
    {
        r = t;
        if (key == t->data)
            return;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (r == NULL)
    {
        *root = p;
    }
    else if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

Node *insert(Node *p, int key)
{
    if (p == NULL)
    {
        Node *t = (Node *)malloc(sizeof(Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = insert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = insert(p->rchild, key);
    }
    return p;
}

int main()
{
    Node *root = NULL;
    Insert(&root, 10);
    Insert(&root, 5);
    Insert(&root, 15);

    Node *foundNode = RSearch(root, 5);
    if (foundNode != NULL)
    {
        printf("Found: %d\n", foundNode->data);
    }
    else
    {
        printf("Not found\n");
    }

    // root = insert(root, 7);
    foundNode = RSearch(root, 7);
    if (foundNode != NULL)
    {
        printf("Found: %d\n", foundNode->data);
    }
    else
    {
        printf("Not found\n");
    }

    return 0;
}
// Expected output:
// Found: 5
// Not Found