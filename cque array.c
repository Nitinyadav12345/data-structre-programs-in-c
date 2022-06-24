#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 100
int size ,front=-1,rear=-1 ,que[max];
void insert(int);
void delt(void);
void display(void);
int main()
{
	int choice,item;
	printf("enter the size of queue\n");
	scanf("%d",&size);
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
void insert(int item)
{
	if(front==(rear+1)%size)
	      printf("queue is full\n");
	else{
		if(rear==-1)
		   front=0;
		rear=(rear+1)%size;
		que[rear]=item;
		printf("success\n");   
	}      
}
void delt(void)
{
  if(front==-1)
      printf("queue is empty\n");
  else{
  	if(front==rear && front != -1){
  		rear=-1;
  		front=-1;
	  }
	 else{
	 	front=(front+1)%size;
	 } 
	 printf("successfully deleted\n");
  }	
}
void display(void)
{   int i;
    if(front==-1)
        printf("it is empty queue\n");
    else{
	if(rear>=front)
	{
		for(i=front;i<=rear;i++)
		    printf("%d\t",que[i]);
	}
	else
	{
		for(i=front;i<size;i++)
		    printf("%d\t",que[i]);
		for(i=0;i<=rear;i++)
		    printf("%d\t",que[i]);    
	}
}
}
