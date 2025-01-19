#include <stdio.h>
#define size 5

int queue[size];
int front = -1;
int rear = -1;

int isEMPTY() {
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

void peek() {
    if (isEMPTY()) {
        printf("Queue is empty!!!\n");
    } else {
        printf("Element at front position is %d\n", queue[front]);
    }
}

int isFULL() {
    if (rear == size - 1)
        return 1;
    else
        return 0;
}

void Enqueue(int data) {
    if (isFULL()) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
    }
}

void Dequeue() {
    if (isEMPTY()) {
        printf("Queue is empty\n");
    } else {
        printf("Element deleted from queue is %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;  // Reset the queue
        }
    }
}

void Display() {
    int i;
    if (isEMPTY()) {
        printf("Queue is empty!!!\n");
    } else {
        printf("Queue elements are: ");
        for (i = front; i <= rear; i++) {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int num, choice;

    while (1) {
        printf("MENU||\n");
        printf("1.ENQUEUE  2.DEQUEUE  3.PEEK  4.SHOW  5.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter any element for enqueue: ");
                scanf("%d", &num);
                Enqueue(num);
                break;

            case 2:
                Dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                Display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
