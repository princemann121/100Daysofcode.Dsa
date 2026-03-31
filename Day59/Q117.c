/* Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal */


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

// Search in inorder
int search(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree
struct Node* buildTreeUtil(int inorder[], int postorder[],
                           int start, int end, int* postIndex) {

    if (start > end)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = newNode(rootVal);

    if (start == end)
        return root;

    int inIndex = search(inorder, start, end, rootVal);

    // IMPORTANT: build right first
    root->right = buildTreeUtil(inorder, postorder, inIndex + 1, end, postIndex);
    root->left = buildTreeUtil(inorder, postorder, start, inIndex - 1, postIndex);

    return root;
}

// Wrapper
struct Node* buildTree(int inorder[], int postorder[], int n) {
    int postIndex = n - 1;
    return buildTreeUtil(inorder, postorder, 0, n - 1, &postIndex);
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

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    struct Node* root = buildTree(inorder, postorder, n);

    printf("Inorder of constructed tree: ");
    inorderPrint(root);

    return 0;
}