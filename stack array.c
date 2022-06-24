#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 100
int size,top=-1;
int stack[max];
int push(int);
int pop(int);
void display(int);

int main()
{   
    int choice;
    printf("enter the size of stack\n");
	scanf("%d",&size);
	while(1)
	{
		printf("for exit press 0\n");
		printf("for push press 1\n");
		printf("for pop press 2\n");
		printf("for traverse press 3\n");
		
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: top = push(top);
				break;
			case 2: top = pop(top);
			    break;	
			case 3: display(top);
			    break;
			default: exit(0);	    
		}
	}
	getch();
	return 0;
}
int push( int top1)
{
	int item;
	printf("enter the value \n");
	scanf("%d",&item);
	if(top1  == size -1)
           printf( "overflow or stack is full\n");
    else{
          top1 = top1 + 1;
          stack[top1] = item;}
          printf("push done \n\n\n");
          return top1;
}
int pop(int top2)
{
	if(top2 == -1)
	    printf("stack is empty\n");
    else{
    	printf("%d element is deleted\n",stack[top2]);
    	top2=top2-1;
        }
        printf("pop done\n\n\n");
        return top2;
}
void display( int top3)
{   int i;
	if(top3==-1)
	printf("stack is empty\n");
	else{
		i=top3;
		while(i >= 0){
			printf("%d \t",stack[i]);
			i=i-1;
		}
		}
	printf("\n\n");	
}
