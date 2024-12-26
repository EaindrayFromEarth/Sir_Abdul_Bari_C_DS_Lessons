#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    RED,
    BLACK
} Color;

typedef struct Node
{
    int data;
    Color color;
    struct Node *left, *right, *parent;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED; // New nodes are red by default
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void rotateLeft(Node **root, Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == NULL)
    {
        *root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rotateRight(Node **root, Node *y)
{
    Node *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
    {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == NULL)
    {
        *root = x;
    }
    else if (y == y->parent->left)
    {
        y->parent->left = x;
    }
    else
    {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

void fixViolation(Node **root, Node *newNode)
{
    Node *parent = NULL;
    Node *grandparent = NULL;

    while ((newNode != *root) && (newNode->color == RED) && (newNode->parent->color == RED))
    {
        parent = newNode->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left)
        {
            Node *uncle = grandparent->right;
            if (uncle != NULL && uncle->color == RED)
            {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grandparent;
            }
            else
            {
                if (newNode == parent->right)
                {
                    rotateLeft(root, parent);
                    newNode = parent;
                    parent = newNode->parent;
                }
                rotateRight(root, grandparent);
                Color temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                newNode = parent;
            }
        }
        else
        {
            Node *uncle = grandparent->left;
            if (uncle != NULL && uncle->color == RED)
            {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                newNode = grandparent;
            }
            else
            {
                if (newNode == parent->left)
                {
                    rotateRight(root, parent);
                    newNode = parent;
                    parent = newNode->parent;
                }
                rotateLeft(root, grandparent);
                Color temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                newNode = parent;
            }
        }
    }
    (*root)->color = BLACK;
}

void insert(Node **root, int data)
{
    Node *newNode = createNode(data);
    if (*root == NULL)
    {
        *root = newNode;
    }
    else
    {
        Node *current = *root;
        Node *parent = NULL;
        while (current != NULL)
        {
            parent = current;
            if (newNode->data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        newNode->parent = parent;
        if (newNode->data < parent->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }
    fixViolation(root, newNode);
}

Node *search(Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

Node *minimum(Node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

void fixDoubleBlack(Node **root, Node *x)
{
    if (x == *root)
        return; // If x is root, just return

    Node *sibling = NULL;
    Node *parent = NULL;

    while (x != *root && (x == NULL || x->color == BLACK))
    {
        parent = x->parent;

        if (x == parent->left)
        {
            sibling = parent->right;

            if (sibling != NULL && sibling->color == RED)
            {
                sibling->color = BLACK;
                parent->color = RED;
                rotateLeft(root, parent);
                sibling = parent->right;
            }

            if ((sibling->left == NULL || sibling->left->color == BLACK) &&
                (sibling->right == NULL || sibling->right->color == BLACK))
            {
                sibling->color = RED;
                x = parent;
            }
            else
            {
                if (sibling->right == NULL || sibling->right->color == BLACK)
                {
                    if (sibling->left != NULL)
                    {
                        sibling->left->color = BLACK;
                    }
                    sibling->color = RED;
                    rotateRight(root, sibling);
                    sibling = parent->right;
                }

                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->right != NULL)
                {
                    sibling->right->color = BLACK;
                }
                rotateLeft(root, parent);
                x = *root;
            }
        }
        else
        {
            sibling = parent->left;

            if (sibling != NULL && sibling->color == RED)
            {
                sibling->color = BLACK;
                parent->color = RED;
                rotateRight(root, parent);
                sibling = parent->left;
            }

            if ((sibling->right == NULL || sibling->right->color == BLACK) &&
                (sibling->left == NULL || sibling->left->color == BLACK))
            {
                sibling->color = RED;
                x = parent;
            }
            else
            {
                if (sibling->left == NULL || sibling->left->color == BLACK)
                {
                    if (sibling->right != NULL)
                    {
                        sibling->right->color = BLACK;
                    }
                    sibling->color = RED;
                    rotateLeft(root, sibling);
                    sibling = parent->left;
                }

                sibling->color = parent->color;
                parent->color = BLACK;
                if (sibling->left != NULL)
                {
                    sibling->left->color = BLACK;
                }
                rotateRight(root, parent);
                x = *root;
            }
        }
    }
    if (x != NULL)
    {
        x->color = BLACK;
    }
}

void deleteNode(Node **root, Node *node)
{
    Node *y = node;
    Node *x;
    Color originalColor = y->color;

    if (node->left == NULL)
    {
        x = node->right;
        if (node->parent == NULL)
        {
            *root = node->right;
        }
        else if (node == node->parent->left)
        {
            node->parent->left = node->right;
        }
        else
        {
            node->parent->right = node->right;
        }
        if (node->right != NULL)
        {
            node->right->parent = node->parent;
        }
        free(node);
    }
    else if (node->right == NULL)
    {
        x = node->left;
        if (node->parent == NULL)
        {
            *root = node->left;
        }
        else if (node == node->parent->left)
        {
            node->parent->left = node->left;
        }
        else
        {
            node->parent->right = node->left;
        }
        if (node->left != NULL)
        {
            node->left->parent = node->parent;
        }
        free(node);
    }
    else
    {
        y = minimum(node->right);
        originalColor = y->color;
        x = y->right;

        if (y->parent == node)
        {
            if (x != NULL)
            {
                x->parent = y;
            }
        }
        else
        {
            if (y->right != NULL)
            {
                y->right->parent = y->parent;
            }
            y->parent->left = y->right;
            y->right = node->right;
            node->right->parent = y;
        }

        if (node->parent == NULL)
        {
            *root = y;
        }
        else if (node == node->parent->left)
        {
            node->parent->left = y;
        }
        else
        {
            node->parent->right = y;
        }

        y->parent = node->parent;
        y->left = node->left;
        y->color = node->color;

        if (node->left != NULL)
        {
            node->left->parent = y;
        }

        free(node);
        x = (originalColor == BLACK) ? y->right : NULL;
    }

    if (originalColor == BLACK)
    {
        fixDoubleBlack(root, x);
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d (%s) ", root->data, root->color == RED ? "RED" : "BLACK");
        inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 15);
    insert(&root, 30);
    insert(&root, 25);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    Node *foundNode = search(root, 15);
    if (foundNode != NULL)
    {
        printf("Found: %d\n", foundNode->data);
    }
    else
    {
        printf("Not found\n");
    }

    // Deleting a node
    printf("Deleting 15...\n");
    deleteNode(&root, foundNode);

    printf("Inorder Traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}

// Inorder Traversal: 10 (BLACK) 15 (BLACK) 20 (RED) 25 (BLACK) 30 (RED)
// Found: 15
// Deleting 15...
// Inorder Traversal after deletion: 10 (BLACK) 20 (BLACK) 25 (BLACK) 30 (RED)