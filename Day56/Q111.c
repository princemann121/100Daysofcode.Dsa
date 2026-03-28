/* Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL) */

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
// Build tree
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
        if (nodes[i]) {
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
// Check symmetry
int isSymmetric(struct Node* left, struct Node* right) {
    if (!left && !right)

        return 1;
    if (!left || !right || left->data != right->data)

        return 0;
    return isSymmetric(left->left, right->right) && isSymmetric(left->
right, right->left);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)

        scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    if (isSymmetric(root->left, root->right))

        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}   




