#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100
int rear=-1,front=-1,size;
int que[max];
void insert(int);
void delt(void);
void traverse(void);
int main()
{   
    int choice,item;
    printf("enter the size of queue\n");
	scanf("%d",&size);
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
			case 3: traverse();
			    break;
			default: exit(0);	    
		}
	}
	getch();
	return 0;
}
void insert(int item)
{
	if(rear==size-1)
	   printf("overflow\n");
	else{
		if(rear==-1)
		    front =front+1;
		 rear=rear+1;
		 que[rear]=item;   
	    printf("successfully entered\n");
	}   
	
}
void delt(void)
{
	if(front==-1)
	     printf("underflow\n");
	 else{
	 	if(front ==  rear && front != -1 )
	 	  {
	 	  	front = -1;
	 	  	rear = -1;
		   }
		else{
		 front=front+1;
		 }
		 
		   printf("item deleted\n");
	 }    
}
void traverse(void)
{   
    int i;
	if(front==-1)
	   printf("queue is empty\n");
    else{
    	for(i=front;i<=rear;i++)
    	  printf("%d\t",que[i]);
	}
	printf("\n");
}
