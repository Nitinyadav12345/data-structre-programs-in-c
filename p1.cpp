#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int arr[5][5];
	int a,b;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>arr[i][j];
			if(arr[i][j]==1){
			 a=i;
			 b=j;	
			}
		}
	}
    a=a-2;
    b=ba-2;
    a=abs(a)+abs(b);
	cout<<a;
}
