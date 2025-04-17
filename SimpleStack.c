#include <stdio.h>
#define maxsize 5

int stack[maxsize];
int top = -1;

void push(){
    if(top == maxsize - 1)
        printf("Stack Overflow\n");
    else{
        int value;
        printf("Enter a value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }
}

void pop(){
    if (top == -1){
        printf("Stack Underflow\n");
    } else {
        printf("Popped value: %d\n", stack[top]);
        top--;
    }
}

void peek(){
    if(top == -1)
        printf("Stack is empty\n");
    else
        printf("Top element is: %d\n", stack[top]);
}

void display(){
    if(top == -1)
        printf("Stack is empty\n");
    else{
        printf("Stack elements are: ");
        int i;
        for(i = top; i >= 0; i--){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice, value;
    while(1){
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push();
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
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }    
}
