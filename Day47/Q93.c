/* Problem: Height of Binary Tree

Implement the solution for this problem.

Input:
- Input specifications */
#include  <stdio.h>
#include  <stdlib.h>
// Node structure
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
// Build tree from level order (-1 = NULL)
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)

        return NULL;
    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            if (left < n)
                nodes[i]->left = nodes[left];
            if (right < n)
                nodes[i]->right = nodes[right];
        }
    }
    return nodes[0];            
}
// Height of Binary Tree
int height(struct Node* root) {
    if (root == NULL)
        return 0;   
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);  
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;   
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter node values in level order (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    int treeHeight = height(root);  
    printf("Height of the binary tree: %d\n", treeHeight);
    return 0;
}



