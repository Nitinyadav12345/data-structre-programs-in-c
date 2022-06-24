#include<stdio.h>
#include<stdlib.h>

int main()
{ 
  printf("hello its nitin yadav\n");
  struct node{
    float coff;
    int exp;
    struct node *link;
  } *start=NULL, *ptr,*temp,*prev;
  int n, i=0,j=1;
  printf("enter no. of terms in polynomial  \n");
  scanf("%d",&n);
  while(i<n){
    ptr= (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL){
      printf("memory over flow\n");
      exit(0);
    }
    else{
     printf("enter the coff and exp part of node  %d\n",j);
     scanf("%f %d",&ptr->coff,&ptr->exp);
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
    for(temp=start;temp != NULL;temp=temp->link){
    	if(temp->coff > 0)
    	printf("+");
    	printf("%.1fX^%d",temp->coff,temp->exp);
	}
	return 0;
	}
    
