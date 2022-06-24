#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node *link;
}*head,*temp; 
int n;
struct node* cll_creation(int);
void display(struct node*); 
struct node* insert_first(struct node*);
struct node* insert_last(struct node*);
struct node* insert_any(struct node*,int);
struct node* delete_first(struct node*);
struct node* delete_last(struct node*);
struct node* delete_any(struct node*,int);
int main()
{   head=NULL;
    temp=NULL;  
    int choice,m,a;
    while(1)
    {
    	printf("press 0 for exit \n");
		printf("for creating cll press 1\n");
    	printf("for traversing list press 2\n");
    	printf("for insert at first press 3\n");
    	printf("for insert at last press 4\n");
    	printf("for insert at any press 5\n");
    	printf("for deleting first press 6\n");
    	printf("for deleting last press 7\n");
    	printf("for deleting any position node press 8\n");
    	
    	scanf("%d",&choice);
    	
    	switch(choice)
    	{
    		case 1: printf("enter the no. of nodes\n");
    		        scanf("%d",&n);
    		        head= cll_creation(n);
    		        break;
    		case 2: display(head);
			        break; 
			case 3: head= insert_first(head);
			        break;	
			case 4: head= insert_last(head);
			        break;	
			case 5: printf("enter the pos of node\n");
			        scanf("%d",&m);
					head= insert_any(head,m);
					break;
			case 6: head= delete_first(head);
			        break;	
			case 7: head= delete_last(head);
			        break;
			case 8: printf("enter the position of node\n");
			        scanf("%d",&a);
					head= delete_any(head,a);
					break;							 	       
    		default : exit(0);        
    		        
		}
	}
    getch();
    printf("\n\n\n\n\n");
    return 0;
}
struct node* cll_creation(int s)
{
	struct node   *ptr , *h1=NULL;
	int i;
	for(i=1;i<=s;i++)
	{
		ptr=malloc(sizeof(struct node));
		if(ptr==NULL)
		{
			printf("memory exhausted\n");
			exit(0);
		}
		else
		{
			printf("enter the value of node %d:- ",i);
			scanf("%d",&ptr->data);
			ptr->link=NULL;
			if(h1==NULL)
			{
				h1=ptr;
				h1->link=h1;
				temp=h1;
			}
			else
			{
				temp->link=ptr;
				ptr->link=h1;
				temp=temp->link;
			}
		}
	}
	printf("creation successfull\n");
	printf("\n\n");
	return h1;
}

void display(struct node* tempa)
{   struct node* start;
    start=tempa;
	if(tempa==NULL)
	{
		printf("list is empty\n");
		exit(0);
	}
	else
	{
		do{
			printf("%d \t",tempa->data);
			tempa=tempa->link;
		}while(tempa!=start);
	}
	printf("\n\n");
}

struct node* insert_first(struct node* h2 )
{
 struct node  *newnode,*temp1; 
 newnode=malloc(sizeof(struct node));
 if(newnode==NULL)	
 {
 	printf("memory exhausted\n");
 	exit(0);
 }
 else
 {
 	newnode->link=NULL;
 	printf("enter the value ");
 	scanf("%d",&newnode->data);
 	if(h2==NULL){
 		h2=newnode;
 		h2->link=h2;
	 }
	else{
		temp1=h2;
		while(temp1->link!=h2)
		temp1=temp1->link;
		newnode->link=h2;
		h2=newnode;
		temp1->link=newnode;
	}
 }
 printf("insertion  success\n\n\n");
 return h2;
}
struct node* insert_last(struct node* h3 )
{
 struct node  *newnode1,*temp2; 
 newnode1=malloc(sizeof(struct node));
 if(newnode1==NULL)	
 {
 	printf("memory exhausted\n");
 	exit(0);
 }
 else
 {
 	newnode1->link=NULL;
 	printf("enter the value ");
 	scanf("%d",&newnode1->data);
 	if(h3==NULL){
 		h3=newnode1;
 		h3->link=h3;
	 }
	else{
		temp2=h3;
		while(temp2->link!=h3)
		temp2=temp2->link;
		newnode1->link=h3;
		temp2->link=newnode1;
		newnode1->link=h3;
	}
 }
 printf("insertion success\n\n\n");
 return h3;
}
struct node* insert_any(struct node* h4,int pos)
{
	 struct node  *newnode2,*temp3;
	 int j; 
 newnode2=malloc(sizeof(struct node));
 if(newnode2==NULL)	
 {
 	printf("memory exhausted\n");
 	exit(0);
 }
 else
 {
 	if(pos>n+1){
 		printf("invalid position\n");
	 }
	 else if(pos==1){
	 	h4=insert_first(h4);
	 }
	 else{
	 	printf("enter the value\n");
	 	scanf("%d",&newnode2->data);
	 	temp3=h4;
	 	j=1;
	 	while(j<pos-1){
	 		temp3=temp3->link;
	 		j++;
		 }
		newnode2->link=temp3->link;
		temp3->link=newnode2;                  
		printf("insertion   success\n");
	 }
 }
 printf("insert at %d success\n\n\n",pos);
 return h4;
}
struct node* delete_first(struct node* h5)
{
	struct node* temp4;
	if(h5==NULL){
		printf("list is empty can't perform deletion\n");
		exit(0);
	}
	else
	{   	temp4=h5;
		if(h5->link==h5){
		                 temp4->link=NULL;
			             h5=NULL;
		}
		else{
			while(temp4->link!=h5)
		    temp4=temp4->link;
		    temp4->link=h5->link;
		    temp4=h5;
		    h5=h5->link;
		    temp4->link=NULL;
		}
		free(temp4);
		temp4=NULL;
	}
	printf("deletion success\n\n\n");
	return h5;
}
struct node* delete_last(struct node* h6)
{
	struct node *temp5,*prev;
	if(h6==NULL){
		printf("list is empty can't perform deletion\n");
		exit(0);
	}
	else
	{   
		if(h6->link==h6){
			             temp5=h6;
		                 temp5->link=NULL;
			             h6=NULL;
		}
		else{      prev = NULL;
             for(temp5 = h6; temp5->link!= h6; temp5= temp5->link)
                          prev = temp5;
             prev->link = temp5->link;
             temp5->link = NULL;
			 }
		free(temp5);temp5=NULL;	 
		}
	printf("deletion success\n\n\n");
	return h6;
}
struct node* delete_any(struct node* h7,int pos1)
{   
    int i;
	struct node* temp6, *prev1;
	if(h7==NULL){
	printf("list is empty can't perform deletion\n ");
	exit(0);
    }
    else
    {
    	if(pos1>n)
    	printf("invalid position \n");
    	else if(pos1==1){
    		h7=delete_first(h7);
		}
		else{
			temp6=h7;
			prev1=NULL;
			for(i=1;i<pos1;i++){
				prev1=temp6;
				temp6=temp6->link;
			}
			prev1->link=temp6->link;
			temp6->link=NULL;
			free(temp6);
			temp6=NULL;
		}
	}
	printf("deletion success at node %d\n\n\n",pos1);
	return h7;
}

