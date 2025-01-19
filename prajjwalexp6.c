#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/' || x == '%') return 2;
    if (x == '^' || x == '$') return 3;
    return 0;
}

int main() {
    char exp[100], rev[100];
    char *e, x;
    int i = 0;

       printf("Enter the infix expression: ");
    scanf("%s", exp);

        strrev(exp);

    e = exp;
    while (*e != '\0') {
        if (isalnum(*e)) {
                       rev[i++] = *e;
        } else if (*e == ')') {
                       push(*e);
        } else if (*e == '(') {
                       while ((x = pop()) != ')') {
                rev[i++] = x;
            }
        } else 


           {
            
            while (priority(stack[top]) > priority(*e)) {
                rev[i++] = pop();
            }
            push(*e);
        }
        e++;
    }


    while (top != -1) {
        rev[i++] = pop();
    }

    rev[i] = '\0'; 
        strrev(rev);

       printf("The prefix expression is: %s\n", rev);

    return 0;
}
