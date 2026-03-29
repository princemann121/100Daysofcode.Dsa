#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Flatten function (optimized)
struct Node* prev = NULL;

void flatten(struct Node* root) {
    if (!root) return;

    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

// Print flattened list
void printList(struct Node* root) {
    while (root) {
        printf("%d ", root->data);
        root = root->right;
    }
}

int main() {
   
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);

    flatten(root);

    printList(root);

    return 0;
}