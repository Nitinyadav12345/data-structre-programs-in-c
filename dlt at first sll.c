 #include <stdio.h>
#include<stdlib.h>

void main()
{
  struct node{
    int info;
    struct node *link;
  } *start=NULL, *ptr,*temp;
  int n, i=0,j=1;
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
   printf("do you want to dlt 1st node(1/0)\n") ;
   scanf("%d",&j);
   if(j==1){
     temp=start;
     if(start==NULL){
       printf("no link exist\n");
       exit(0);
     }
      else if(temp->link==NULL){
       printf("list gone empty\n");
       start=NULL;
       free(temp);
       temp=NULL;}
       else{
       start=temp->link;
       free(temp);
       temp=NULL;}}
    else{
      printf("no problem sir\n");
      exit(0);}
         temp=start;
    printf("the element of sll is \n");
    while(temp!=NULL) {
      printf("%d \t",temp->info);
      temp=temp->link;}       
return 0;
}
