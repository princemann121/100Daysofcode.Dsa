/* Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level). */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Level Order Traversal (line by line)
void levelOrder(struct Node* root) {
    if (!root) return;

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];
            printf("%d ", curr->data);

            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }
        printf("\n"); // next level
    }
}

int main() {
    // Example tree
    struct Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    levelOrder(root);

    return 0;
}