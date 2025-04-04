#include <stdio.h>
#define maxsize 5

int queue[maxsize];

int front = -1, rear = -1;

void enqueue(){
    int x;
    if(rear == maxsize - 1){
        printf("Queue Overflow\n");
    } else {
        printf("Enter the element \n");
        scanf("%d", &x);
        if (front == -1){
            front = 0;
            rear = 0;
            queue[rear] = x;
        } else {
            rear++;
            queue[rear] = x;
        }
    }
}

void dequeue(){
    if(front == -1){
        printf("Queue Underflow\n");
    } else if(rear == front){
        front = -1;
        rear = -1;
    } else {
        printf("Dequeued element is %d\n", queue[front]);
        front++;
    }
}

void display(){
    int i;
    if(front == -1){
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: \n");
        for(int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice;
    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: enqueue();
                break;
            case 2: dequeue();
                break;
            case 3: display();
                break;
            case 4: printf("Exiting...\n");
                return 0;
            default: printf("Invalid choice\n");
        }
    }
}

