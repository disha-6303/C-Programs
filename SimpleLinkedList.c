#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

node * temp;
node * head = NULL;

node * createnode(){
    node * newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL)
        printf("Memory allocation failed\n");
    else {
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
    }
    return newnode;
}

void insertatBegining(node ** head){
    node * newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("Enter data \n");
    scanf("%d", &newnode->data);
    newnode->next = *head;
    *head = newnode;
}

void insertAtMiddle(node ** head){
    if(*head == NULL){
        insertatBegining(head);
    } else {
        int position;
        temp = *head;
        node * prev;

        printf("Enter position to insert: ");
        scanf("%d", &position);
        node * newnode = (node *) malloc (sizeof(node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        int i = 1;
        while (i < position && temp != NULL){
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = newnode;
        newnode->next = temp;
    }
}

void insertAtEnd(node ** head){
    temp = *head;
    if (*head == NULL){
        insertatBegining(head);
    } else {
        node * newnode = (node *) malloc (sizeof(node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void deleteAtBeginning(node ** head){
    temp = *head;
    if(*head == NULL){
        printf("List is empty\n");
    } else {
        *head = temp->next;  // Move head to next node
        printf("Deleted node: %d\n", temp->data);
        free(temp);
    }
}

void deleteAtEnd(node ** head){
    node * prev;
    temp = *head;
    if(*head == NULL){
        printf("List is empty\n");
    } else {
        while(temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("Deleted node: %d\n", temp->data);
        free(temp);
    }
}

void display(node ** head){
    temp = *head;
    if(*head == NULL){
        printf("List is empty\n");
    } else {
        printf("List: ");
        while(temp != NULL){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    head = NULL;
    temp = head;
    int choice;
    while(1){
        printf("\n1. Insert at beginning\n2. Insert at middle\n3. Insert at end\n4. Delete at beginning\n5. Delete at end\n6. Display\n7. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insertatBegining(&head);
                break;
            case 2:
                insertAtMiddle(&head);
                break;
            case 3:
                insertAtEnd(&head);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                display(&head);
                break;
            case 7:
                printf("Thanks\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

