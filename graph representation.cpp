#include<bits/stdc++.h>
using namespace std;
vector<bool> v(n,false);
void dfs(int s){
  if(v[s]) return;
  v[s]=true;
  for(auto u: adl[s]){
    dfs(u);
  }
}
int main(){
  int  n,v,x,y; /* n is no. of edges v is no of edges */
  cin>>n,v;
  vector<pair<int ,int>> adl[n];
  for(int i=0;i<v;i++){
    cout<<"enter the value of ending vertix and its weight";
    cin>>x>>y;
    adl[i].push_back({x,y});
  }

  return  0;
}
