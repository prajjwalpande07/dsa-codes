#include<stdio.h>
#include<conio.h>
#include<process.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    if ((front == -1) && (rear == -1)) 
        return 1;
    else 
        return 0;
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty!!!\n");
    } else {
        printf("Element at front position is %d\n", queue[front]);
    }
}

int isFull() {
    if ((rear + 1) % SIZE == front) 
        return 1;
    else 
        return 0;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full\n");
    } else if ((front == -1) && (rear == -1)) {
        front = 0;
        rear = 0;
        queue[rear] = data;
    } else {
        rear = (rear + 1) % SIZE;
        queue[rear] = data;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("The dequeue element is %d\n", queue[front]);
        front = -1;
        rear = -1;
    } else {
        printf("Dequeued element is %d\n", queue[front]);
        front = (front + 1) % SIZE;
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty!!!\n");
    } else if (front > rear) {
        printf("\nCircular queue elements are: ");
        for (i = front; i < SIZE; i++) 
            printf("%d\t", queue[i]);
        for (i = 0; i <= rear; i++) 
            printf("%d\t", queue[i]);
        printf("\n");
    } else {
        printf("\nCircular queue elements are: ");
        for (i = front; i <= rear; i++) 
            printf("%d\t", queue[i]);
        printf("\n");
    }
}

void main() {
    int num, choice;
    clrscr();
    
    while (1) {
        printf("MENU::\n");
        printf("1.Enqueue  2.Dequeue  3.Peek  4.Show  5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter any element for enqueue: ");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    getch();
}
