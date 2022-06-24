#include<iostream>
using namespace std;
int* insert(int* arr,int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        for(j=i-1;j>=0;j--){
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
    scanf("%d", &n);
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int* index=insert(arr,n);
    for(int i=0;i<n;i++){
        cout<<index[i]<<" ";
    }
    
}
