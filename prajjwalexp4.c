#include <stdio.h>
#include <stdlib.h> // For exit()

#define MAX 5

int stack[MAX];
int top = -1;

int isfull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Elements of stack are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

void peek() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
    } else {
        printf("Topmost element of stack is %d\n", stack[top]);
    }
}

void push(int data) {
    if (isfull()) {
        printf("Stack is Full\n");
    } else {
        stack[++top] = data;
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
    } else {
        printf("Element popped from stack is %d\n", stack[top--]);
    }
}

int main() {
    int num, choice;

    while (1) {
        printf("MENU::\n");
        printf("1. PUSH  2. POP  3. PEEK  4. SHOW  5. EXIT\n");
        printf("Enter Your Choice:\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element for push:\n");
            scanf("%d", &num);
            push(num);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}
