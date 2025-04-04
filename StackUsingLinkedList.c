#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* top = NULL; // Stack top

// Function to create a new node
node* createnode() {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    printf("Enter data you want to push into stack: ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;
    return newNode;
}

// Push function
void push(node** top) {
    node* newNode = createnode();
    if (!newNode) return; // Handle malloc failure
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto stack\n", newNode->data);
}

// Pop function
void pop(node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return;
    }
    node* temp = *top;
    *top = temp->next;
    printf("Popped %d from stack\n", temp->data);
    free(temp);
}

// Peek function
void peek(node** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is %d\n", (*top)->data);
    }
}

// Display function
void display(node** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    node* temp = *top;
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(&top);
                break;
            case 2:
                pop(&top);
                break;
            case 3:
                peek(&top);
                break;
            case 4:
                display(&top);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

