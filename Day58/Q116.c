/* Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree. */
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

// Search value in inorder
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTreeUtil(int preorder[], int inorder[],
                           int start, int end, int* preIndex) {

    if (start > end)
        return NULL;

    int rootVal = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = newNode(rootVal);

    if (start == end)
        return root;

    int inIndex = search(inorder, start, end, rootVal);

    root->left = buildTreeUtil(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTreeUtil(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// Wrapper function
struct Node* buildTree(int preorder[], int inorder[], int n) {
    int preIndex = 0;
    return buildTreeUtil(preorder, inorder, 0, n - 1, &preIndex);
}

// Inorder print (to verify)
void inorderPrint(struct Node* root) {
    if (root) {
        inorderPrint(root->left);
        printf("%d ", root->data);
        inorderPrint(root->right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = buildTree(preorder, inorder, n);

    printf("Inorder of constructed tree: ");
    inorderPrint(root);

    return 0;
}