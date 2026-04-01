/* You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree. */

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

int cameras = 0;

// DFS states: 0 = need camera, 1 = has camera, 2 = covered
int dfs(struct Node* root) {
    if (root == NULL)
        return 2;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 0 || right == 0) {
        cameras++;
        return 1;
    }

    if (left == 1 || right == 1)
        return 2;

    return 0;
}

int minCamera(struct Node* root) {
    if (dfs(root) == 0)
        cameras++;

    return cameras;
}

int main() {
    
    struct Node* root = newNode(0);
    root->left = newNode(0);
    root->right = newNode(0);
    root->left->left = newNode(0);

    printf("Minimum Cameras: %d\n", minCamera(root));

    return 0;
}