#include<stdio.h>
#include<conio.h>
#define max 100
int arr[max][max];
int main()
{
	int size,i,j,sum1=0,sum2=0;
	printf("enter the order of square matrix\n");
	scanf("%d",&size);
	printf("enter the elements of square matrix\n");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf("enter the value of element arr[%d][%d] ",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
		for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf(" the value of element arr[%d][%d]=%d\n",i,j,arr[i][j]);
		}
	}
	for(i=0;i<size;i++){
	     sum1=sum1+arr[i][i];	
	}
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++){
			if(size-1==i+j){
				sum2=sum2+arr[i][j];
			}
		}
	}
	printf("%d",sum1-sum2);
}
