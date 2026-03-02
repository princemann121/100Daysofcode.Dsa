/* You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Push values into stack (array)
int fillStack(struct Node* head, int stack[]) {
    int top = -1;
    while(head != NULL) {
        stack[++top] = head->data;
        head = head->next;
    }
    return top;
}

// Add numbers
struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {

    int stack1[1000], stack2[1000];
    int top1 = fillStack(l1, stack1);
    int top2 = fillStack(l2, stack2);

    int carry = 0;
    struct Node* result = NULL;

    while(top1 >= 0 || top2 >= 0 || carry != 0) {

        int sum = carry;

        if(top1 >= 0)
            sum += stack1[top1--];

        if(top2 >= 0)
            sum += stack2[top2--];

        carry = sum / 10;

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = sum % 10;

        // Insert at beginning
        newNode->next = result;
        result = newNode;
    }

    return result;
}

int main() {

    int n1, n2;

    scanf("%d", &n1);

    struct Node *head1 = NULL, *temp = NULL, *newNode;

    for(int i = 0; i < n1; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head1 == NULL) {
            head1 = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &n2);

    struct Node *head2 = NULL;
    temp = NULL;

    for(int i = 0; i < n2; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head2 == NULL) {
            head2 = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    struct Node* result = addTwoNumbers(head1, head2);

    while(result != NULL) {
        printf("%d ", result->data);
        result = result->next;
    }

    return 0;
}