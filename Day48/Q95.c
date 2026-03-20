/* Problem: Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications */

#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};  
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int countLeafNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int main() {
    // Example tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Number of Leaf Nodes: %d\n", countLeafNodes(root));

    return 0;
}               

