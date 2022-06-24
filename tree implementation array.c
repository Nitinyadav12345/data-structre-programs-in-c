#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char tree[100];
void root(char);
int count;
void rchild(char ,int);
void lchild(char ,int);
void traverse(int);
void main()
{
	int choice,parent,last;
    char key; 
while(1){
	printf("its ny bigboss ,tree implementation through array\n");
	printf("choose 1 for store root \n");
	printf("choose 2 for lchild  \n");
	printf("choose 3 for rchild \n");
	printf("choose 4 for traversal\n");
	printf("choose 0 for exit\n ");
    scanf("%d",&choice);
    
    
    switch(choice){
    	case 1:printf("enter the key value of root\n");
    	       scanf(" %c",&key);
    	       
			   root(key);
			   break;
        case 2:printf("enter the key value,index of parent of lchild\n");
    	       scanf(" %c %d",&key,&parent);
    	       lchild(key,parent);break;
    	case 3:printf("enter the key value,index of parent of rchild\n");
    	       scanf(" %c %d",&key,&parent);
    	       rchild(key,parent);break;
    	case 4:printf("enter the SIZE \n") ;
    	       scanf("%d",&last);
		       traverse(last);break; 
		
	    case 0: exit(0);
		default: printf("you entred the wrong choice\n");    
	}
    
	}	
}
void root(char key)
{
	if( tree[0]=='\0'){
	
	tree[0]=key;
	}
	else{
		printf("root already exists\n");
	}
}
void lchild(char key, int parent)
{
	if(tree[parent]!='\0'){
	
	 tree[2*parent+1]=key;
	 }
	else{
		printf(" PARENT NODE DOESNT EXISTS\n");
	} 
}

void rchild(char key,int parent)
{
 if(tree[parent]!='\0'){
 
	 tree[2*parent+2]=key;
	}
	else{
		printf("PARENT NODE DOESNT EXISTS\n");
	} 	
}
void traverse(int last)

{
	int i;
	if(tree[0]=='\0')
	printf("tree does not exists\n");
	else{
	for(i=0;i<=last;i++){
		if(tree[i]=='\0')
		printf("_");
		else
		printf("%c",tree[i]);
	}
}
	printf("\n");
}
