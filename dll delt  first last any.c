#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
  int data;
  struct node* prev;
  struct node* link;
}*head,*temp;
int n;
struct node* dll_creation(int);
void dll_forward(struct node*);
void dll_backward(struct node*);
struct node* deletefirst(struct node*);
struct node* deletelast(struct node*);
struct node* deleteany(struct node*,int);

 void dll_forward(struct node* tempa)
 {
   if(tempa==NULL){
     printf("dll is empty \n");
     exit(0);
     }
   else{
    while(tempa!= NULL){
     printf("%d \t",tempa->data);
     tempa=tempa->link;
   }  
 } 
 }
  void dll_backward(struct node* tempb)
  {
    if(tempb==NULL){
      printf("empty\n");
    }
  else{
    while(tempb->link!=NULL){
    	tempb=tempb->link;
	}
    while(tempb!=NULL){
      printf("%d\t",tempb->data);
      tempb=tempb->prev;
    }
  }  
  }



int main()
{   head=NULL;
    temp=NULL;
    int choice,m;
    while(1){
      printf("\nfor creating dll press 1\n");
      printf("for forward travarse press 2\n");
      printf("for backward travarse press 3\n");
      printf("for deleting first node press 4\n");
      printf("for deleting last node press 5\n");
      printf("for delete any pos press 6\n");
      printf("for exit press 0 \n");
      scanf("%d",&choice);
      
      switch(choice){
        case 1:printf("how many nodes you want\n");
        scanf("%d",&n);head=dll_creation(n);
        break;
        case 2: dll_forward(head);
        break;
        case 3: dll_backward(head);
        break;
        case 4: head=deletefirst(head);
        break;
        case 5: head=deletelast(head);
        break;
        case 6: printf("enter pos of node that you want to delete\n");
                 scanf("%d",&m);
                 head=deleteany(head,m);
                 break;
      default: exit(0);  
      
    }
 }
 printf("\n\n");
  
  return 0;
}
struct node* dll_creation(int s)
{
  int i, data;
    struct node *ptr , *head1=NULL;
        for(i=1; i<=s; i++)
        {
            ptr = (struct node *)malloc(sizeof(struct node));
            if(ptr==NULL)
            printf("overflow memory");
            else 
            {  
            printf("Enter data of %d node: ", i);
            scanf("%d", &ptr->data);
            ptr->prev = NULL;
            ptr->link = NULL;
            if(head1==NULL)
            { 
            head1=ptr;
            temp=ptr;
            }
            else
            {
              temp->link=ptr;
              ptr->prev=temp;
              temp=ptr;
            }

            }
        }
        printf("created successfully\n");
        return head1;
    }
    struct node* deletefirst(struct node *h2)
    {
       struct node *temp1;

    if(h2 == NULL)
    
    {
        printf("List is empty.\n");
    }
    else
    {
        temp1 = h2;

        h2= h2->link;
        
        if (h2!=NULL)
            h2->prev = NULL; 

        free(temp1);
        printf("successfully deleted node \n");
    }
    return h2;
    }
    struct node* deletelast(struct node *h3)
	{
		struct node* temp2;
		if(temp== NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp2 = temp;

        temp= temp->prev; 
        
        if (temp != NULL)
            temp->link = NULL; 

        free(temp2);   
    
		printf("successfully deleted node\n");
		}
		return h3;
	}
	struct node*deleteany(struct node *h4, int pos)
{
    struct node *temp3;
    int i;
    if(pos>n)
    {
    printf("invalid position");
    exit(0);
    }

    temp3 = h4;
    for(i=1; i<pos && temp3!=NULL; i++)
    {
        temp3 = temp3->link;
    }

    if(pos== 1)
    {
        h4=deletefirst(h4);
    }
    else if(temp3 == temp)
    {
        h4=deletelast(h4);
    }
    else 
    {
        temp3->prev->link = temp3->link;
        temp3->link->prev = temp3->prev;

        free(temp3); 

        printf("successfully deleted node from  %d position\n", pos);
    }
    
    return h4;

}
	 
	
