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

void remove_same(node *head){
	node *temp1;
	temp1=head->next;
	node *temp2;
	while(temp1!=NULL){
		temp2=temp1->next;
		node *prev=temp2;
		while(temp2!=NULL){
			if(temp2->data==temp1->data){
				prev->next=temp2->next;

			}
			prev=temp2;
			temp2=temp2->next;
		}
		temp1=temp1->next;
	}
}


void main(){
	node *head;
	head->next=NULL;
	int n;
	printf("Enter the no of elements to enter:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		insert_end(head);

	}
	printf("\nBefore removing\n");
	display(head);

	remove_same(head);
	
	printf("\nAfter Removing\n");
	display(head);

}

