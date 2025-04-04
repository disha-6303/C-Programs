#include <stdio.h>
#define MAXSIZE 5

int queue[MAXSIZE];
int front = -1, rear = -1;

void enqueue() {
    int item;
    if ((rear == MAXSIZE - 1 && front == 0) || (front == rear + 1)) {
        printf("Queue Overflow\n");
    } else {
        printf("Enter your data: \n");
        scanf("%d", &item);
        if (front == -1) {
            front = rear = 0;
            queue[rear] = item;
        } else if (rear == MAXSIZE - 1 && front != 0) {
            rear = 0;
            queue[rear] = item;
        } else {
            rear = rear + 1;
            queue[rear] = item;
        }
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
    } else if (rear == front) {
        printf("Dequeued item is %d\n", queue[front]);
        front = rear = -1;
    } else if (front == MAXSIZE - 1) {
        printf("Dequeued item is %d\n", queue[front]);
        front = 0;
    } else {
        printf("Dequeued item is %d\n", queue[front]);
        front = front + 1;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        int i;
        printf("Queue elements are: ");
        if (rear >= front) {
            for (i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (i = front; i < MAXSIZE; i++) {
                printf("%d ", queue[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

