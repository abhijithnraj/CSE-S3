#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
	int data;
	struct NODE *next;

}node;

void insert_end(node *head){
	if(head==NULL){
		printf("\nUNABLE TO ALLOCATE ANY MEMORY\n");
	}
	
	node *new_data;
	new_data= (node *)malloc(sizeof(node));

	//recieving key
	printf("Enter the data value:\n");
	scanf("%d",&new_data->data);
	new_data->next=NULL;

	//creating temperary variable and iterating to the end
	node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
		//iterating over elements

	}
	
	
	//adding the new node to the end of the list \n	
	temp->next=new_data;

	
}
void display(node *head){
	node *temp=head->next;
	int counter=1;
	printf("\n");
	while(temp->next!=NULL){
		printf("%d->",temp->data);
		counter++;
		temp=temp->next;
	}
	printf("%d->NULL\n",temp->data);
}

void break_list(node *head,int n){
	node *temp=head->next;
	node *prev;
	node *cutoff;
	for(int i=0;i<n;i++){
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
	cutoff=temp;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=head->next;
	head->next=cutoff;
}
void main()
{
	node *head;
	head->next=NULL;
	int n;
	printf("Enter the no of elements you want to enter:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		insert_end(head);
	}

	display(head);
	int r;
	printf("Enter the r value at which you want to cutoff at:\n");
	scanf("%d",&r);
	break_list(head,r);
	display(head);
}
