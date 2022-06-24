
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int bisearch(int l,int h,int key ,int* arr ){
	if(l==h){
		if(arr[l]==key){
			return l;
		}
		else
		return 0;
	}
	else{
		int mid =(l+h)/2;
		if(arr[mid]==key){
			return mid;
		}
		else if(arr[mid]>key){
			return bisearch(l,mid-1,key,arr);
		}
		else{
			return bisearch(mid+1,h,key,arr);
		}
	}
}
int main(){
	int i,key,index;
    int n;	
    cin >>n;
	int* arr = new int[n];
	for(i=0;i<n;i++){
            cin>>arr[i];
        }
    for(i=0;i<n;i++){
    	cout<<arr[i]<<" ";
	}  

	cin>>key;
	index = bisearch(0,n-1,key,arr);
	cout<<index;
}
