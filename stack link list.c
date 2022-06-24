#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
}*top=NULL;
struct node* push(struct node*);
struct node* pop(struct node*);
void display(struct node*);

int main()
{   
    int choice;
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
struct node* push(struct node* top1 ){
   struct node* ptr;
   ptr=malloc(sizeof(struct node));
   printf("enter info \n");
   scanf("%d",&ptr->data);
   ptr->link=NULL;
   ptr->link=top1;
   top1 =ptr;
   printf("push done \n\n\n");
   return top1;
}
 struct node* pop(struct node* top2)
{
     struct node* temp;
     temp=top2;
     if(top2==NULL){
       printf("no stack exist\n");
       exit(0);}
      else if(temp->link==NULL){
       printf("stack gone empty\n");
       top2=NULL;
       free(temp);
       temp=NULL;}
       else{
       top2=temp->link;
       free(temp);
       temp=NULL;}
        printf("pop done\n\n\n");
        return top2;
}
void display( struct node* start)
{   struct node* temp1;
    temp1=start;
    printf("element in stack\n");
    while(temp1!=NULL) {
      printf("%d \t",temp1->data);
      temp1=temp1->link;
    }
	printf("\n\n");	
}
