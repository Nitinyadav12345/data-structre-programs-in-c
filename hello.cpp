#include<Bits/stdc++.h>
using namespace std;
int main(){
 
 bool flag=false;
 int m,temp;
 cin>>m;
 int* arr = new int[m];
 for(int i=0;i<m;i++){
 	cin>>arr[i];
 }
 for(int i=0;i<m;i++)
 cout<<arr[i]<<" ";
 for(int i=0;i<m/2;i++)
   {
   	temp=arr[i];
   	arr[i]=arr[m-i-1];
   	arr[m-i-1]=temp;
   }
 for(int i=0;i<m;i++)
 cout<<arr[i]<<" ";
 return 0;
}
