#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	char data;
	struct node* left;
	struct node* right;
};
struct node* creation();
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);

void main()
{
	struct node* root=NULL;
	int choice;
	while(1)
	{
		printf("for creation of tree press 1\n");
		printf("for inorder traversal press 2\n");
		printf("for preorder traversal press 3\n");
		printf("for post order traversal press4\n");
		printf("for exit program press 0\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:root=creation();
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
			default:printf("you entered the wrong choice h\n");
			        break;
		}
	}
}
struct node* creation()
{
	struct node *ptr;
	char var1;
	ptr =  malloc(sizeof(struct node));
	printf("enter data of node\n");
	scanf(" %c",&var1);
	if(var1=='0'){
		return 0;
	}
	ptr->data=var1;
	printf("enter the left child of %c \n",var1);
	ptr->left=creation();
	printf("enter the right child of %c \n",var1);
	ptr->right=creation();
	return ptr;
	
}
void inorder(struct node *root)
{
	if(root==NULL)
	return ;
	inorder(root->left);
	printf("%c",root->data);
	inorder(root->right);
}
void preorder(struct node *root)
{
	if(root==NULL)
	return ;
	printf("%c",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node *root)
{
	if(root==NULL)
	return ;
	postorder(root->left);
	postorder(root->right);
	printf("%c",root->data);
}
