#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{ int i, *ptr, *ptrnew;
ptr =(int*)malloc(2*sizeof(int));
if(ptr == NULL){
printf("The required memory is not available");
exit(0);
}
else{
	
*ptr = 10;
*(ptr+1) = 20;
ptrnew = (int*)realloc(ptr, 3*sizeof(int));
*(ptrnew + 2) = 30;
for(i=0; i<3; i++)
printf("%d\t", *(ptrnew + i));

}
}

