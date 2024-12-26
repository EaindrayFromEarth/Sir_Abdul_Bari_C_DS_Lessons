// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node
// {
//     int keys[3];              // 2-3-4 tree can have up to 3 keys
//     struct Node *children[4]; // 2-3-4 tree can have up to 4 children
//     int numKeys;              // Number of keys in the node
// } Node;

// // Function to create a new node
// Node *createNode(int key)
// {
//     Node *newNode = (Node *)malloc(sizeof(Node));
//     newNode->keys[0] = key;
//     newNode->numKeys = 1;
//     for (int i = 0; i < 4; i++)
//     {
//         newNode->children[i] = NULL;
//     }
//     return newNode;
// }

// // Function to split a full child node
// void splitChild(Node *parent, int index)
// {
//     Node *child = parent->children[index];
//     Node *newChild = createNode(child->keys[1]);

//     // Move the second key of child to parent
//     for (int j = parent->numKeys; j > index; j--)
//     {
//         parent->keys[j] = parent->keys[j - 1];
//         parent->children[j + 1] = parent->children[j];
//     }
//     parent->keys[index] = child->keys[1];
//     parent->children[index + 1] = newChild;
//     parent->numKeys++;

//     // Move the third key and children to the new child
//     newChild->children[0] = child->children[2];
//     newChild->children[1] = child->children[3];
//     newChild->numKeys = 1;

//     child->numKeys = 1;                     // Reduce the number of keys in the original child
//     parent->children[index + 1] = newChild; // Link new child to parent
// }

// // Function to insert a key into a non-full node
// void insertNonFull(Node *node, int key)
// {
//     int i = node->numKeys - 1;

//     if (node->children[0] == NULL)
//     { // Leaf node
//         while (i >= 0 && key < node->keys[i])
//         {
//             node->keys[i + 1] = node->keys[i];
//             i--;
//         }
//         node->keys[i + 1] = key;
//         node->numKeys++;
//     }
//     else
//     { // Internal node
//         while (i >= 0 && key < node->keys[i])
//         {
//             i--;
//         }
//         i++;
//         if (node->children[i]->numKeys == 3)
//         { // If child is full
//             splitChild(node, i);
//             if (key > node->keys[i])
//             {
//                 i++;
//             }
//         }
//         insertNonFull(node->children[i], key);
//     }
// }

// // Function to insert a key into the 2-3-4 tree
// void insert(Node **root, int key)
// {
//     if (*root == NULL)
//     {
//         *root = createNode(key);
//     }
//     else
//     {
//         if ((*root)->numKeys == 3)
//         { // If root is full
//             Node *newRoot = createNode((*root)->keys[1]);
//             newRoot->children[0] = *root;
//             splitChild(newRoot, 0);
//             *root = newRoot;
//             insertNonFull(newRoot, key);
//         }
//         else
//         {
//             insertNonFull(*root, key);
//         }
//     }
// }

// // Function for inorder traversal
// void inorder(Node *root)
// {
//     if (root != NULL)
//     {
//         for (int i = 0; i < root->numKeys; i++)
//         {
//             inorder(root->children[i]);
//             printf("%d ", root->keys[i]);
//         }
//         inorder(root->children[root->numKeys]);
//     }
// }

// // Function to search for a key in the 2-3-4 tree
// Node *search(Node *root, int key)
// {
//     while (root != NULL)
//     {
//         int i = 0;
//         while (i < root->numKeys && key > root->keys[i])
//         {
//             i++;
//         }
//         if (i < root->numKeys && key == root->keys[i])
//         {
//             return root; // Key found
//         }
//         root = root->children[i]; // Move to the appropriate child
//     }
//     return NULL; // Key not found
// }

// int main()
// {
//     Node *root = NULL;
//     insert(&root, 10);
//     insert(&root, 20);
//     insert(&root, 5);
//     insert(&root, 15);
//     insert(&root, 25);

//     printf("Inorder Traversal: ");
//     inorder(root);
//     printf("\n");

//     int searchKey = 15;
//     Node *foundNode = search(root, searchKey);
//     if (foundNode != NULL)
//     {
//         printf("Key %d found in the tree.\n", searchKey);
//     }
//     else
//     {
//         printf("Key %d not found in the tree.\n", searchKey);
//     }

//     return 0;
// }
