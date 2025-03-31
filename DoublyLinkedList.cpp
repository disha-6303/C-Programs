// Doubly Linked List Implementation

#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function prototypes
void createList(struct Node** head);
void displayList(struct Node* head);
void insertAtBeg(struct Node** head);
void insertAtAny(struct Node* head);
void deleteFromBeg(struct Node** head);
void deleteSpecific(struct Node** head);
void countNodes(struct Node* head);
void searchNode(struct Node* head);

int main() {
    int ch;
    struct Node* start = NULL;

    while (1) {
        printf("\n1) Add Node \n2) Display \n3) Insert at Beginning \n4) Insert at any Position");
        printf("\n5) Delete from Beginning \n6) Delete Specific \n7) Count Nodes \n8) Search Node \n9) Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: createList(&start);
                break;
            case 2: displayList(start);
                break;
            case 3: insertAtBeg(&start);
                break;
            case 4: insertAtAny(start);
                break;
            case 5: deleteFromBeg(&start);
                break;
            case 6: deleteSpecific(&start);
                break;
            case 7: countNodes(start);
                break;
            case 8: searchNode(start);
                break;
            case 9: exit(1);
            default: printf("Invalid Choice\n");
        }
    }
}

// Function to create a doubly linked list
void createList(struct Node** head) {
    struct Node *p, *q;
    p = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter a value: ");
    scanf("%d", &p->data);
    p->next = NULL;
    p->prev = NULL;

    if (*head == NULL) {
        *head = p;
    } else {
        q = *head;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
        p->prev = q;
    }
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    struct Node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to insert at the beginning
void insertAtBeg(struct Node** head) {
    struct Node* p;
    int d;

    printf("Enter data: ");
    scanf("%d", &d);

    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = d;
    p->prev = NULL;
    p->next = *head;

    if (*head != NULL) {
        (*head)->prev = p;
    }

    *head = p;
}

// Function to insert at a specific position
void insertAtAny(struct Node* head) {
    struct Node *p, *q;
    int d, pos, i = 1;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter data: ");
    scanf("%d", &d);

    q = head;
    while (i < pos - 1 && q->next != NULL) {
        q = q->next;
        i++;
    }

    if (i != pos - 1) {
        printf("Invalid position\n");
        return;
    }

    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = d;
    p->next = q->next;
    p->prev = q;

    if (q->next != NULL) {
        q->next->prev = p;
    }

    q->next = p;
}

// Function to delete from the beginning
void deleteFromBeg(struct Node** head) {
    struct Node* p;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    p = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(p);
}

// Function to delete a specific node
void deleteSpecific(struct Node** head) {
    struct Node *p, *q;
    int d;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter data to delete: ");
    scanf("%d", &d);

    p = *head;
    while (p != NULL && p->data != d) {
        p = p->next;
    }

    if (p == NULL) {
        printf("Node not found\n");
        return;
    }

    if (p->prev != NULL) {
        p->prev->next = p->next;
    } else {
        *head = p->next;
    }

    if (p->next != NULL) {
        p->next->prev = p->prev;
    }

    free(p);
}

// Function to count the number of nodes
void countNodes(struct Node* head) {
    struct Node* p;
    int count = 0;

    p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }

    printf("Total nodes: %d\n", count);
}

// Function to search for a node
void searchNode(struct Node* head) {
    struct Node* p;
    int d, pos = 1;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter data to search: ");
    scanf("%d", &d);

    p = head;
    while (p != NULL && p->data != d) {
        p = p->next;
        pos++;
    }

    if (p == NULL) {
        printf("Node not found\n");
    } else {
        printf("Node found at position %d\n", pos);
    }
}

