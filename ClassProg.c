#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
void createList(struct Node** head);
void displayList(struct Node* head);
void insertatbeg(struct Node** head);

int main(){
	int ch;
	struct Node* start = NULL;
	
	while(1){
		printf("\n1) Add Node \n2) Display \n3) Delete Node \n4)Exit");
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
