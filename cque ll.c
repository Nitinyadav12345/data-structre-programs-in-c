#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};
struct node *rear=NULL,*front=NULL;
void insert(int item)
{
	struct node *ptr;
	ptr=malloc(sizeof(struct node));
	if(ptr==NULL)
	printf("memory overflow\n");
	else
	{   
	    ptr->data=item;
		if(rear==NULL){
			rear=ptr;
			front=ptr;
			ptr->link=front;
		}
		else{
			rear->link=ptr;
			ptr->link=front;
			rear=ptr;
		}
		printf("successfully inserted\n");
	 } 
}
void delt(void)
{
	struct node *temp;
	if(front==rear){
		front=NULL;
		rear=NULL;
	} 
	else
	{
		temp=front;
		rear->link=front->link;
		front=front->link;
		free(temp);
		temp=NULL;
	}
	printf("successfully deleted\n");
}
void display(void)
{   
    struct node *temp;
	temp=front;
	do{
		printf("%d\t",temp->data);
		temp=temp->link;
	}while(temp!=rear->link);
	printf("\n");
}
int main()
{
		int choice,item;
	while(1)
	{
	printf("1.enque 2.deque 3.display \n");
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
	return 0;
}
