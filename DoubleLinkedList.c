#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} node;

node *head = NULL;

// Function to create a new node
node *createnode() {
    node *newnode = (node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Insert at the beginning
void insertatBeginning(node **head) {
    node *newnode = createnode();
    if (*head == NULL) {
        *head = newnode;
    } else {
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    }
}

// Insert at the end
void insertatEnd(node **head) {
    if (*head == NULL) {
        insertatBeginning(head);
        return;
    }
    node *newnode = createnode();
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

// Insert at a given position
void insertatMiddle(node **head) {
    if (*head == NULL) {
        insertatBeginning(head);
        return;
    }
    node *newnode = createnode();
    int position, i = 1;
    printf("Enter position to insert: ");
    scanf("%d", &position);
    node *temp = *head;

    while (i < position - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

// Delete at the beginning
void deleteatBeginning(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = *head;
    *head = temp->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete at the middle
void deleteatMiddle(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    int position, i = 1;
    printf("Enter position to delete: ");
    scanf("%d", &position);
    node *temp = *head;
    
    while (i < position && temp->next != NULL) {
        temp = temp->next;
        i++;
    }
    if (i < position) {
        printf("Invalid position\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp == *head) {
        *head = temp->next;
    }
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete at the end
void deleteatEnd(node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display the list
void display(node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Reverse display
void reverseddisplay(node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Reversed List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at middle\n4. Delete at beginning\n5. Delete at middle\n6. Delete at end\n7. Display\n8. Reverse Display\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insertatBeginning(&head);
                break;
            case 2:
                insertatEnd(&head);
                break;
            case 3:
                insertatMiddle(&head);
                break;
            case 4:
                deleteatBeginning(&head);
                break;
            case 5:
                deleteatMiddle(&head);
                break;
            case 6:
                deleteatEnd(&head);
                break;
            case 7:
                display(head);
                break;
            case 8:
                reverseddisplay(head);
                break;
            case 9:
                printf("Thanks for using the program!\n");
                return 0;
            default:
                printf("Invalid choice, try again!\n");
        }
    }
}

