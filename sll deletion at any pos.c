#include <stdio.h>
#include<stdlib.h>

int main()
{ 
  printf("hello its nitin yadav\n");
  struct node{
    int info;
    struct node *link;
  } *start=NULL, *ptr,*temp,*prev;
  int n, i=0,j=1,pos=NULL;
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
     if(start==NULL){
       start=ptr;
       temp=start;
       }
       else{
         temp->link=ptr;
         temp=temp->link;
       }
     }
     i=i+1;
    }
    temp=start;
    printf("the element of sll is \n");
    while(temp!=NULL) {
      printf("%d \t",temp->info);
      temp=temp->link;
    }
    printf("do you want dlt a node(1/0) \n ");
    scanf("%d",&j);
    printf("enter the pos of element to dlt\n");
    scanf("%d",&pos);
    if(j==1){
    	if(start ==  NULL){
    		printf("condition of under flow\n");
    		exit(0);
		}
		else if(pos>n){
			printf("not valid position\n");
			exit(0);
		}
		else if(pos==1){
			temp=start;
			start=temp->link;
			free(temp);
			temp=NULL;
		}
		else{
			prev=NULL;
			temp=start;
			for(i=1;i<pos;i++){
				prev=temp;
				temp=temp->link;
			}
			prev->link=temp->link;
			temp->link=NULL;
			free(temp);
			temp=NULL;
		}
	}
	else{
		printf("no problem sir\n");
	}
	 temp=start;
    printf("the element of sll is \n");
    while(temp!=NULL) {
      printf("%d \t",temp->info);
      temp=temp->link;
    }
 return 0;   
}
