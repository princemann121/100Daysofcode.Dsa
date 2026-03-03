/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type. */

#include <stdio.h>
#include <string.h>

#define MAX 10000

int isValid(char *s) {

    char stack[MAX];
    int top = -1;

    for(int i = 0; s[i] != '\0'; i++) {

        char c = s[i];

        // Opening brackets
        if(c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        }
        else {
            // If stack empty → invalid
            if(top == -1)
                return 0;

            char t = stack[top--];

            if((c == ')' && t != '(') ||
               (c == '}' && t != '{') ||
               (c == ']' && t != '['))
                return 0;
        }
    }

    return (top == -1);
}

int main() {

    char s[MAX];

    scanf("%s", s);

    if(isValid(s))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}