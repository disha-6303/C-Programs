// Circular Doubly Linked List Implementation

#include <stdio.h>
#include <stdlib.h>

// Node structure for Circular Doubly Linked List
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function prototypes
void createList(struct Node** head);
void displayList(struct Node* head);
void insertAtBeg(struct Node** head);
void insertAtAny(struct Node** head);
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
            case 4: insertAtAny(&start);
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

// Function to create a circular doubly linked list
void createList(struct Node** head) {
    struct Node* p, *q;
    p = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter a value: ");
    scanf("%d", &p->data);
    p->next = p;
    p->prev = p;

    if (*head == NULL) {
        *head = p;
    } else {
        q = (*head)->prev;
        q->next = p;
        p->prev = q;
        p->next = *head;
        (*head)->prev = p;
    }
}

// Function to display the circular doubly linked list
void displayList(struct Node* head) {
    struct Node* ptr = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
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

    if (*head == NULL) {
        p->next = p;
        p->prev = p;
        *head = p;
    } else {
        struct Node* last = (*head)->prev;
        p->next = *head;
        p->prev = last;
        last->next = p;
        (*head)->prev = p;
        *head = p;
    }
}

// Function to insert at a specific position
void insertAtAny(struct Node** head) {
    struct Node *p, *q;
    int d, pos, i = 1;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter data: ");
    scanf("%d", &d);

    q = *head;
    do {
        if (i == pos - 1) break;
        q = q->next;
        i++;
    } while (q != *head);

    if (i != pos - 1) {
        printf("Invalid position\n");
        return;
    }

    p = (struct Node*)malloc(sizeof(struct Node));
    
    p->data = d;
    p->next = q->next;
    p->prev = q;
    q->next->prev = p;
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

    if (p->next == p) { // Only one node in the list
        free(p);
        *head = NULL;
    } else {
        struct Node* last = p->prev;
        *head = p->next;
        (*head)->prev = last;
        last->next = *head;
        free(p);
    }
}

// Function to delete a specific node
void deleteSpecific(struct Node** head) {
    struct Node *p;
    int d;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter data to delete: ");
    scanf("%d", &d);

    p = *head;
    do {
        if (p->data == d) break;
        p = p->next;
    } while (p != *head);

    if (p->data != d) {
        printf("Node not found\n");
        return;
    }

    if (p->next == p) { // Only one node
        free(p);
        *head = NULL;
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;

        if (p == *head) {
            *head = p->next;
        }

        free(p);
    }
}

// Function to count the number of nodes
void countNodes(struct Node* head) {
    struct Node* p;
    int count = 0;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    p = head;
    do {
        count++;
        p = p->next;
    } while (p != head);

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
    do {
        if (p->data == d) {
            printf("Node found at position %d\n", pos);
            return;
        }
        p = p->next;
        pos++;
    } while (p != head);

    printf("Node not found\n");
}

