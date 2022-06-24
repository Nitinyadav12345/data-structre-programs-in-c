#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *tail;

int n;
struct node* createList(int );
void displayList(struct node *);
struct node* deleteFromBeginning(struct node *);
struct node* deleteFromEnd(struct node *);
struct node* deleteFromN(struct node *,int );


void main()
{
    int m, data, choice=1;

    head = NULL;
    tail= NULL;

    while(1)
    {
        printf("DOUBLY LINKED LIST PROGRAM\n");
        printf("1. Create List\n");
        printf("2. Delete node - from beginning\n");
        printf("3. Delete node - from end\n");
        printf("4. Delete node - from N\n");
        printf("5. Display list\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                head=createList(n);
                break;
            case 2:
                head=deleteFromBeginning(head);
                break;
            case 3:
               head= deleteFromEnd(head);
                break;
            case 4:
                printf("Enter the node position which you want to delete: ");
                scanf("%d", &m);
               head= deleteFromN(head,m);
                break;
            case 5:
                displayList(head);
                break;
            case 0:
                exit(0);
            default:
                printf("Error! Invalid choice. Please choose between 0-5");
        }

        printf("\n\n\n\n\n");
    }

    getch();
}

struct node* createList(int s)
{
    int i, data;
    struct node *newNode , *h1=NULL;
        for(i=1; i<=s; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode==NULL)
            printf("overflow");
            else 
            {  
            printf("Enter data of %d node: ", i);
            scanf("%d", &newNode->data);
            newNode->prev = NULL;
            newNode->next = NULL;
            if(h1==NULL)
            { 
            h1=newNode;
            tail=newNode;
            }
            else
            {
              tail->next=newNode;
              newNode->prev=tail;
              tail=newNode;
            }

            }
        }
        return h1;

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
}


void displayList(struct node *temp)
{
  
 int k=1;

    if(temp == NULL)
    printf("List is empty.\n");

    else
    {
       while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", k, temp->data);

            k++;
            temp = temp->next;
        }
    }
}


struct node* deleteFromBeginning(struct node*h2)
{
    struct node *temp;

    if(h2 == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp= h2;

        h2= h2->next;
        
        if (h2!=NULL)
            h2->prev = NULL; 

        free(temp);
        printf("SUCCESSFULLY DELETED NODE\n");
    }
    return h2;
}

struct node* deleteFromEnd(struct node *h3)
{
    struct node *temp;

    if(tail== NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = tail;

        tail= tail->prev; 
        
        if (tail != NULL)
            tail->next = NULL; 

        free(temp);   
        printf("SUCCESSFULLY DELETED.\n");
    }
    return h3;
}



struct node*deleteFromN(struct node *h4, int position)
{
    struct node *current;
    int i;
    if(position>n)
    {
    printf("invalid position");
    exit(0);
    }

    current = h4;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(position == 1)
    {
        h4=deleteFromBeginning(h4);
    }
    else if(current == tail)
    {
        h4=deleteFromEnd(h4);
    }
    else 
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current); 

        printf("SUCCESSFULLY DELETED NODE FROM %d POSITION.\n", position);
    }
    
    return h4;
}
