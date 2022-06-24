#include<stdio.h>
#include<conio.h>
#define max 100
int length;
int a[max];
void swap(int* ,int*);
void heapify( int );
void build_max_heap();
int main()
{   int size;
	int k;
	printf("enter the size of an array\n");
	scanf("%d",&length);
	size=length;
	for(k=0;k<length;k++)
	{
		printf("enter the element at index %d :-",k);
		scanf("%d",&a[k]);
	}
	 build_max_heap();
	for(k=length-1;k>=1;k--)
	{
		swap(&a[0],&a[k]);
		length--;
		heapify(0);
		
	}
	for(k=0;k<size;k++)
	{
		printf("%d\t",a[k]);
	}
	return 0;
}
void swap(int *x, int *y)
{
	int temp;
	temp= *x;
	*x=*y;
	*y=temp;
}
void heapify( int i)
{
	int l,r,largest;
	l= 2*i+1;
	r= 2*i+2;
	if(l<=length-1 && a[l]>a[i])
	{
		largest=l;
	}
	else{
		largest=i;
	}
	if(r<=length-1 && a[r]>a[largest])
	{
		largest=r;
	}
	if(largest != i){
		swap(&a[i] , &a[largest]);
		heapify(largest);
	}
}

void build_max_heap(void)
{
	int j;
	for(j=length/2 -1;j>=0;j--)
	{
		heapify(j);
	}
}

