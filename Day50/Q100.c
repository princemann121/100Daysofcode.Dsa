/* You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null. */

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
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Search and return subtree root
struct Node* searchBST(struct Node* root, int val) {
    if (root == NULL || root->data == val)
        return root;

    if (val < root->data)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

// Print inorder (to verify subtree)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int n, x, key;
    scanf("%d", &n);

    struct Node* root = NULL;

    // Build BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    // Value to search
    scanf("%d", &key);

    struct Node* result = searchBST(root, key);

    if (result == NULL) {
        printf("Not Found\n");
    } else {
        printf("Subtree Inorder: ");
        inorder(result);  // print subtree
    }

    return 0;
}