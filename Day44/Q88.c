/* Given the root of a binary tree, return the preorder traversal of its nodes' values. */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorder(struct TreeNode* root){
    if(root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main(){

    // Creating the example tree
    struct TreeNode* root = createNode(1);
    root->right = createNode(2);
    root->right->left = createNode(3);

    printf("Preorder Traversal: ");
    preorder(root);

    return 0;
}