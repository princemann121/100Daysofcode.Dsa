/* Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).” */

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

// Find LCA
struct Node* lowestCommonAncestor(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    if (p < root->data && q < root->data)
        return lowestCommonAncestor(root->left, p, q);

    if (p > root->data && q > root->data)
        return lowestCommonAncestor(root->right, p, q);

    return root; // split point or equal
}

int main() {
    int n, x, p, q;
    scanf("%d", &n);

    struct Node* root = NULL;

    // Build BST
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    // Input nodes
    scanf("%d %d", &p, &q);

    struct Node* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL)
        printf("LCA: %d\n", lca->data);
    else
        printf("LCA not found\n");

    return 0;
}