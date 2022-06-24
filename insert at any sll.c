#include <stdio.h>
#include<stdlib.h>

void main()
{
  struct node{
    int info;
    struct node *link;
  } *start=NULL, *ptr,*temp;
  int n, i=0,j=1,pos, item, h;
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
   printf("do you want to insert a node(1/0)\n");
   scanf("%d",&h);
   printf("enter pos for insert a node \n");
   scanf("%d",&pos); 
   if(h==1){
     ptr = (struct node*)malloc(sizeof(struct node));
       if(ptr==NULL){
         printf("memory overflow\n");
         exit(0);
       }
      else if(pos > n+1){
       printf("invalid pos\n");
       exit(0);
     }
     
     else{
       printf("enter the info\n");
       scanf("%d",&item);
       ptr->info=item;
       ptr->link=NULL;
       if(pos==1){
         ptr->link=start;
         start=ptr;}
       else{
         i=1;
         temp=start;
         while(i<pos-1){
           temp=temp->link;
           i++;}
       ptr->link=temp->link;
       temp->link=ptr;}
      }
     }
   temp=start;
    printf("the element of sll is \n");
    while(temp!=NULL) {
      printf("%d \t",temp->info);
      temp=temp->link;
    }
 return 0;
}
