#include<iostream>
#include<vector>
using namespace std;
void swap(int*x ,int*y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int partition(int* arr ,int l,int h){
int i,j,pivot;
i=l;j=h;
pivot=arr[l];
while(i<j){
do{
	i++;
}while(arr[i]<=pivot);
while(arr[j]>pivot){
j--;
}
if(i<j){
	swap(&arr[i],&arr[j]);
}
}
swap(&arr[l],&arr[j]);
return j;
}
void quicksort(int* arr,int l,int h){
	if(l>=h){
		return;
	}
	int j = partition(arr,l,h);
	quicksort(arr,l,j);
	quicksort(arr,j+1,h); 
}
int main(){
int n;
cin>>n;
int* arr=new int[n];
for(int i=0;i<n;i++){
	cin>>arr[i];
}	
quicksort(arr,0,n-1);
for(int i=0;i<n;i++){
	cout<<arr[i]<<" ";
}	
delete(arr);
}
