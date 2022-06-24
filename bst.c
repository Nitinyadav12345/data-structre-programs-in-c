#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* insert(struct node*,int);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

void main()
{
	struct node* root=NULL;
	int choice,i,n,info;
	while(1)
	{
		printf("for creating a binary search tree press 1\n");
		printf("for inorder traversal press 2\n");
		printf("for preorder traversal press 3\n");
		printf("for post order traversal press4\n");
		printf("for exit program press 0\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("enter the no. of element\n");
			       scanf("%d",&n); 
			       for(i=0;i<n;i++){
			       printf("enter the element\n");
			       scanf("%d",&info);
			       root=insert(root,info);}
			       
		           break;
			case 2:printf("inorder traversal is\n");
			       inorder(root);
			       printf("\n");
			       break;
			case 3:printf("preorder traversal is\n");
			       preorder(root);
			       printf("\n");
			       break;
			case 4:printf("postorder traversal is\n");
			       postorder(root);
			       printf("\n");
			       break;
			case 0:exit(0);
			default:printf("you entered the wrong choice\n");
			        break;
		}
	}
}
struct node* insert(struct node* root,int info)
{
	struct node* newnode;
	if(root==NULL)
	{
		newnode = malloc(sizeof(struct node));
		if(newnode==NULL){
			return NULL;
		}
		else{
			newnode->data=info;
			newnode->left=newnode->right=NULL;
			root=newnode;
		}
	}
	else{
		if(info>root->data)
		{
			root->right=insert(root->right,info);
		}
		else{
			root->left =insert(root->left,info);
		}
	}
	return root;
	
}

void inorder(struct node *root)
{
	if(root==NULL)
	return ;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}
void preorder(struct node *root)
{
	if(root==NULL)
	 return  ;
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node *root)
{
	if(root==NULL)
	return ;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);
}
