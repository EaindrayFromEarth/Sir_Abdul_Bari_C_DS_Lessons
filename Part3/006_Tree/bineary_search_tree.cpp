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

int Height(Node *p)
{
    if (p == NULL)
        return -1;
    int leftHeight = Height(p->lchild);
    int rightHeight = Height(p->rchild);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

Node *InPre(Node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

Node *InSucc(Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

Node *Delete(Node *p, int key)
{
    if (p == NULL)
        return NULL;

    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (p->lchild == NULL && p->rchild == NULL)
        {
            free(p);
            return NULL;
        }
        else if (p->lchild == NULL)
        {
            Node *temp = p->rchild;
            free(p);
            return temp;
        }
        else if (p->rchild == NULL)
        {
            Node *temp = p->lchild;
            free(p);
            return temp;
        }
        else
        {
            Node *q;
            if (Height(p->lchild) > Height(p->rchild))
            {
                q = InPre(p->lchild);
                p->data = q->data;
                p->lchild = Delete(p->lchild, q->data);
            }
            else
            {
                q = InSucc(p->rchild);
                p->data = q->data;
                p->rchild = Delete(p->rchild, q->data);
            }
        }
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

    foundNode = RSearch(root, 7);
    if (foundNode != NULL)
    {
        printf("Found: %d\n", foundNode->data);
    }
    else
    {
        printf("Not found\n");
    }
    root = Delete(root, 5);
    foundNode = RSearch(root, 5);
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

// Found: 5
// Not found
// Not found