#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void createList(struct Node** head);
void displayList(struct Node* head);
void insertatbeg(struct Node** head);
void insertatany(struct Node* head);
void deleteFromBeg(struct Node** head);
void deleteSpecific(struct Node** head);
void countNodes(struct Node* head);
void searchNode(struct Node* head);

int main(){
    int ch;
    struct Node* start = NULL;

    while(1){
        printf("\n1) Add Node \n2) Display \n3) Insert at beginning \n4) Insert at any position \n5) Delete from Beginning");
        printf("\n6) Delete Specific \n7) Count Nodes \n8) Search Node \n9) Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1 : createList(&start);
                break;
            case 2 : displayList(start);
                break;
            case 3 : insertatbeg(&start);
                 break;
            case 4 : insertatany(start);
                 break;
            case 5 : deleteFromBeg(&start);
                 break;
            case 6 : deleteSpecific(&start);
                 break;
            case 7 : countNodes(start);
                 break;
            case 8 : searchNode(start);
                 break;
            case 9: exit(0);
            default : printf("Invalid Choice\n");
        }
    }
}

// Create a Linked List
void createList(struct Node** head){
    struct Node *p, *q;
    if(*head == NULL){
        p = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter A Value: ");
        scanf("%d", &p->data);
        p->next = NULL;
        *head = p;
    } else {
        q = *head;
        while(q->next != NULL){
            q = q->next;
        }
        p = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter A Value: ");
        scanf("%d", &p->data);
        p->next = NULL;
        q->next = p;
    }
}

// Display the Linked List
void displayList(struct Node* head){
    struct Node* ptr = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while(ptr != NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Insert at Beginning
void insertatbeg(struct Node **head){
    struct Node *p;
    int d;
    printf("Enter data: ");
    scanf("%d", &d);
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = d;
    p->next = *head;
    *head = p;
}

// Insert at Any Position
void insertatany(struct Node* head){
    struct Node *p, *q;
    int key, d;
    q = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter value after which to insert: ");
    scanf("%d", &key);

    while (q != NULL && q->data != key) {
        q = q->next;
    }

    if (q == NULL) {
        printf("Node not found\n");
        return;
    }

    p = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter new node value: ");
    scanf("%d", &d);

    p->data = d;
    p->next = q->next;
    q->next = p;
}

// Delete from Beginning
void deleteFromBeg(struct Node** head){
    struct Node *p;
    if (*head == NULL){
        printf("List is empty\n");
        return;
    }
    p = *head;
    *head = (*head)->next;
    free(p);
}

// Delete Specific Node
void deleteSpecific(struct Node** head){
    struct Node *p, *q;
    int d;
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    printf("Enter data to delete: ");
    scanf("%d", &d);

    if ((*head)->data == d){
        deleteFromBeg(head);
        return;
    }

    q = *head;
    while (q->next != NULL && q->next->data != d){
        q = q->next;
    }

    if (q->next == NULL){
        printf("Node not found\n");
        return;
    }

    p = q->next;
    q->next = p->next;
    free(p);
}

// Count Nodes
void countNodes(struct Node* head){
    struct Node* p = head;
    int count = 0;
    while (p != NULL){
        count++;
        p = p->next;
    }
    printf("Total Nodes: %d\n", count);
}

// Search a Node
void searchNode(struct Node* head){
    struct Node* p = head;
    int d;
    printf("Enter data to search: ");
    scanf("%d", &d);

    while (p != NULL){
        if (p->data == d){
            printf("Node found\n");
            return;
        }
        p = p->next;
    }
    printf("Node not found\n");
}

