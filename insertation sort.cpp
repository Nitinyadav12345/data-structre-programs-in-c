#include<bits/stdc++.h>
using namespace std;  
int main(){
  vector<int> v;
  int x,n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x;
    v.push_back(x);
  }
int key,j;
  for(int i=1;i<n;i++){
    key = v[i];
    j=i-1;
    while( j>=0 && key < v[j]){
      v[j+1]=v[j];
      j--;
    }
  v[j+1]=key;
  }
 for(int i=0;i<n;i++){
   cout<<v[i]<<" ";
 }
 return 0;
}
