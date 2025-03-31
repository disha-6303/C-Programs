//Linked List (Simple Singly Linked List)//

#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
void createList(struct Node** head);
void displayList(struct Node* head);
void insertatbeg(struct Node** head);
void insertatany(struct node* head);
void deleteFromBeg(struct node** head);
void deleteSpecific(struct node** head);
void countNodes(struct node* head);
void searchNode(struct node* head);

int main(){
	int ch;
	struct Node* start = NULL;

	while(1){
		printf("\n1) Add Node \n2) Display \n3) Insert in the beginning \n4)Insert at any n\5)Delete from Beginning \n6)Delete Specific \n7)Count Nodes \n8)Search Node ");
		printf("")
		printf("\nEnter Choice:");
		scanf("%d", &ch);

		switch(ch){
			case 1 : createList(&start);
				break;
			case 2 : displayList(start);
				break;
			case 3 : insertatbeg(&start);
					 break;
			case 4: exit(1);
			default : printf("Invalid Choice");
		}
	}
}

void createList(struct Node** head){
	struct Node *p, *q;
	if(*head == NULL){
		p = (struct Node*) malloc(sizeof(struct Node));
		printf("Enter A Value:");
		scanf("%d", &p->data);
		p->next = NULL;

		*head = p;
			}else {
		q = *head;
		while(q->next != NULL){
			q = q->next;
		}
		
		p = (struct Node*) malloc(sizeof(struct Node));
		printf("Enter A Value:");
		scanf("%d", &p->data);
		p->next = NULL;
		
		q->next = p;
	}
}
void displayList(struct Node* head){
	struct Node* ptr = head;
	while(ptr != NULL){
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
}

void insertatbeg(struct Node **head)
{
	struct Node *p;
	int d;
	printf("\n enter data");
	scanf("%d",&d);
	p=(struct Node*)malloc(sizeof(struct Node));
	p->data=d;
	p->next=*head;
	*head=p;
}