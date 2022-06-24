#include <stdio.h>
#define max 100000
int main(){
    int size,d,i,j,a[max],temp;
    scanf("%d",&size);
    scanf("%d",&d);
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<d;i++){
    	for(j=0;j<size-1;j++){
    		temp=a[j];
    		a[j]=a[j+1];
    		a[j+1]=temp;
		}
	}
    
    for(i=0;i<size;i++){
        printf("%d\t",a[i]);
    }
    
}
