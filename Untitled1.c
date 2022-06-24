#include<iostream>
using namespace std;
int* insert(int* arr,int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
                
            }
            else{
                break;
            }
            
        }
        arr[j+1]=temp;
        
    }
    return arr;
}
int main(){
    int n;
    cout<<"enter the number";
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    int* index=insert(arr,n);
    for(int i=0;i<n;i++){
        cout<<index[i]<<" ";
    }
    
}
