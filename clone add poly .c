#include<stdio.h>
#include<stdlib.h>
struct node{
    float coff;
    int exp;
    struct node *link;
  } *start1=NULL,*start2=NULL,*start=NULL,*ptr,*temp1,*temp2,*temp,*prev;
  struct node* poly_creation(void);
  void display(struct node *start,struct node*temp);
  void display(struct node *start,struct node *temp){
  	 for(temp=start;temp != NULL;temp=temp->link){
    	if(temp->coff > 0)
    	printf("+");
    	printf("%.1fX^%d",temp->coff,temp->exp);
	}
  }
  struct node* poly_creation(){
  int n, i=0,j=1;
  printf("enter no. of terms in polynomial  \n");
  printf("enter the value  of exponent in descending order\n");
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
return start;


	}
	
	 
	int main(){
		start1=poly_creation();
		printf("the polynomial 1 is:\n");
		display(start1,temp1);
		printf("\n");
		start2=poly_creation();
		printf("the polynomial 2 is:\n");
	    display(start2,temp2);
		printf("\n") ;
		if(start1!=NULL&&start2!=NULL){	
		temp1=start1;
		temp2=start2;
		while(temp1!=NULL&&temp2!=NULL){
			if(temp1->exp==temp2->exp && temp1->coff+temp2->coff==0){
				temp1=temp1->link;
				temp2=temp2->link;
				continue;
			}
			ptr=malloc(sizeof(struct node));
			if(ptr==NULL){
				printf("memory over flow\n");
			}
			else{
				ptr->link=NULL;
				if(start==NULL){
					start=ptr;
					temp=ptr;
				}
				else{
					temp->link=ptr;
					temp=ptr;
					}
			}
			if(temp1->exp==temp2->exp && temp1->coff+temp2->coff!=0){
				temp->coff=temp1->coff+temp2->coff;
				temp->exp=temp1->exp;
				temp1=temp1->link;
				temp2=temp2->link;
			}
			else if(temp1->exp >temp2->exp){
				temp->coff=temp1->coff;
				temp->exp=temp1->exp;
				temp1=temp1->link;
			}
			else{
				temp->coff=temp2->coff;
				temp->exp=temp2->exp;
				temp2=temp2->link;
			}	
			
			
		}
		if(temp1!=NULL&&temp2==NULL){
			temp->link=temp1;
		}
		if(temp2!=NULL&&temp1==NULL){
		temp->link=temp2;	
		}
	}
		if(start1!=NULL&&start2==NULL){
			start=start1;
			temp=temp1;
		}
		if(start2!=NULL&&start1==NULL){
			start=start2;
			temp=temp2;
		}
		if(start1==NULL&&start2==NULL){
			printf("no list exist\n");
			start=NULL;
    	}
    	printf("the sum of two polynomials\n");
		display(start,temp)	;
		printf("\n");
		return 0;
	}
    
