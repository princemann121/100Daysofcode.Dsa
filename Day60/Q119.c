/* Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal */

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

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0)
        return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n)
            nodes[i]->left = nodes[left];

        if (right < n)
            nodes[i]->right = nodes[right];
    }

    return nodes[0];
}

// Count nodes
int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check Complete Binary Tree
int isComplete(struct Node* root, int index, int total) {
    if (!root) return 1;

    if (index >= total)
        return 0;

    return isComplete(root->left, 2*index + 1, total) &&
           isComplete(root->right, 2*index + 2, total);
}

// Check Heap Property
int isHeap(struct Node* root) {
    if (!root->left && !root->right)
        return 1;

    if (!root->right)
        return (root->data <= root->left->data) &&
               isHeap(root->left);

    return (root->data <= root->left->data &&
            root->data <= root->right->data) &&
           isHeap(root->left) &&
           isHeap(root->right);
}

// Main check
int isMinHeap(struct Node* root) {
    int total = countNodes(root);

    if (isComplete(root, 0, total) && isHeap(root))
        return 1;
    else
        return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    if (isMinHeap(root))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}