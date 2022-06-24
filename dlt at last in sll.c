#include <stdio.h>
#include<stdlib.h>

void main(){
  struct node{
    int info;
    struct node *link;
  }*ptr, *temp, *start=NULL, *prev;
  int i=1;
  char ch;
  printf("for creating sll(y/n)\n");
  scanf("%s",&ch);
  while(ch=='y'){
    ptr=malloc(sizeof(struct node));
    if(ptr==NULL){
      printf("memory over  flow\n");
      exit(0);}
    else{ 
       printf("enter the info of node \n");
       i++;
       scanf("%d",&ptr->info);
       ptr->link=NULL;
       ptr->link=start;
       start=ptr;
       printf("want to create new node(y/n)\n");
       scanf("%s",&ch);}
       }
   temp=start;
   printf("the elements of sll\n");
   while(temp!=NULL){
     printf("%d\t",temp->info);
     temp=temp->link;} 
   printf("\n the no. nodes are %d\n",i-1);
   printf("for deleting last node(y/n)\n");
   scanf("%s",&ch);
   if(ch=='y'){
     if(start==NULL){
       printf("no existing sll can't perform del\n");
       exit(0);}
     else if(start->link==NULL){
           temp=start;
           start=NULL;
           free(temp);
           temp=NULL;
           printf("list gone empty\n");}
          else{
     for(temp=start;temp->link!=NULL;temp=temp->link){
           prev=temp;}
          prev->link=NULL;
          free(temp);
          temp=NULL;}
   printf("the elements of sll \n");
   temp=start;
   while(temp!=NULL){
     printf("%d\t",temp->info);
     temp=temp->link;}
   printf("the nodes in the sll is %d",i-2);}
   else{
     printf("no problem sir\n"); 
     printf("the elements of sll \n");
   temp=start;
   while(temp!=NULL){
     printf("%d\t",temp->info);
     temp=temp->link;}
   printf("\n the nodes in the sll is %d\n",i-1);
   }
return 0; 
 }
