#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
 struct node{
    int info;
    struct node *prev;
    struct node *link;
  } *start=NULL, *ptr,*temp,*prev;
 void dll_forward(void)	;
 void dll_backward(void);
 void dll_forward(){
 	if(start==NULL){
 		printf("dll is empty \n");
 		exit(0);
 		}
 	else{
 		for(temp=start;temp!=NULL;temp=temp->link)
 		printf("%d \t",temp->info);
	 }	
 }
  void dll_backward(){
  	if(start==NULL){
  		printf("empty\n");
	  }
	else{
		for(temp=start;temp->link!=NULL;temp=temp->link){
		}
		for(;temp!=NULL;temp=temp->prev){
			printf("%d\t",temp->info);
		}
	}  
  }
int main()
{ int n,i=0,j=1,choice,pos;  
  printf("hello its nitin yadav\n");
  printf("enter no. of nodes \n");
  scanf("%d",&n);
  while(i<n){
    ptr= (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
      printf("memory over flow\n");
      exit(0);
    }
    else{
     printf("enter the info part of node  %d\n",j);
     scanf("%d",&ptr->info);
     j++;
     ptr->link= NULL;
     ptr->prev=NULL;
     if(start==NULL){
       start=ptr;
       temp=start;
       }
       else{
         temp->link=ptr;
         ptr->prev=temp;
         temp=ptr;
       }
     }
     i=i+1;
    }
    printf("set choice 1 for forward travesal , choice 2 for backward traversal\n");
    scanf("%d",&choice);
    switch(choice){
    	case 1: printf("dll forward \n");
    	dll_forward();break;
    	case 2: printf("dll backward\n");
    	dll_backward();break;
    	default: printf("entered the wrong choice\n");
	}
	printf("for insert a new node at any  pos(1/0)\n");
	scanf("%d",&choice);
	printf("enter the position of node \n");
	scanf("%d",&pos);
	if(choice==1){
		ptr=malloc(sizeof(struct node));
		if(ptr==NULL){
			printf("memory overflow\n");
			exit(0);
		}
		else{
			printf("enter the info\n");
			scanf("%d",&ptr->info);
			ptr->prev=NULL;
			ptr->link=NULL;
			if(pos>n+1){
				printf("invalid position\n");
				exit(0);
			}
			else if(pos==1){
				if(start==NULL){
                   start=ptr;
                   }
                else{
                    ptr->link=start;
                    start->prev=ptr;
                    start=ptr;
                    }
				}
			else{
				temp=start;
				for(i=1;i<pos-1;i++)
				temp=temp->link;
				ptr->link=temp->link;
	            if(pos != n+1){
				temp->link->prev = ptr;}
               ptr->prev = temp;
               temp->link = ptr;
			   
			}	
		}
	}
	else{
	printf("no problem\n");
	}
	printf("set choice 1 for forward travesal , choice 2 for backward traversal\n");
    scanf("%d",&choice);
    switch(choice){
    	case 1: printf("dll forward \n");
    	dll_forward();break;
    	case 2: printf("dll backward\n");
    	dll_backward();break;
    	default: printf("entered the wrong choice\n");
	}
    return 0;
}
