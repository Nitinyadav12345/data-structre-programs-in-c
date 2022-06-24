#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node *front=NULL,*rear=NULL;
void insert(int item)
{
	struct node* ptr;
    ptr=malloc(sizeof(struct node));
	if(ptr==NULL){
		printf("memory overflow\n");
		}
	else{
		ptr->data=item;
		ptr->next=NULL;
		if(rear==NULL){
			front =ptr;
			rear =ptr;
		}
		else{
			rear->next=ptr;
			rear=ptr;
		}
		printf("successfully entered\n");
	}	
}
void delt(void){
	struct node *temp;
	if(front==NULL)
	      printf("underflow \n");
	else if(front->next==NULL)
	{
		temp=front;
		front=NULL;
		rear=NULL;
		free(temp);
		temp=NULL;
		printf("success\n");
	}  
	else
	{
		temp=front;
		front=temp->next;
		temp->next=NULL;
		free(temp);
		temp=NULL;
		printf("success\n");
	}   
		
}
void display(void)
{   
    struct node *temp;
	if(front==NULL)
	   printf("queue is empty\n");
	else
	{
		temp=front;
		while(temp!=rear->next)
		{
		 printf("%d\t",temp->data);
		 temp=temp->next;	
		}
	} 
	printf("\n");
}
int main()
{
	int choice,item;
	while(1)
	{
		printf("for exit press 0\n");
		printf("for enque press 1\n");
		printf("for deque press 2\n");
		printf("for traverse press 3\n");
		
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter the element\n");
			       scanf("%d",&item);
			       insert(item);
				break;
			case 2: delt();
			    break;	
			case 3: display();
			    break;
			default: exit(0);	    
		}
	}
	getch();
	return 0;
}
