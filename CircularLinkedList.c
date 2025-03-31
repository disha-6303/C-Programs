#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

node* createnode(){
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    node* newnode = (node*) malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertNode(node** head){
    node* newnode = createnode();
    if(*head == NULL){
        *head = newnode;
        newnode->next = *head;
        return;
    }
    node* current = *head;
    while (current->next != *head){
        current = current->next;
    }
    current->next = newnode;
    newnode->next = *head;
}

void display(node* head){
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("...\n");
}

int main(){
    node* head = NULL;
    int choice;
    do{
        printf("\n1. Insert node\n2. Display\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insertNode(&head);
                break;
            case 2:
                display(head);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 3);
    return 0;
}

