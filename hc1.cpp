/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

**************************************************************/
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
*/
int sockMerchant(int n, vector<int> ar) {
sort(ar.begin(),ar.end());
int count=0 ,pair=0;
int i=0,j;
while(i<n){
    for(j=0;j<n;j++){
      if(ar[i]==ar[j]){
          count++;
      }
      else{
          break;
      }
    }
    pair=pair+(count%2);
    count=0;
    i=j;
}
return pair;
}

int main()
{
	vector<int> v;
	int x,a;
    cin>>x;
    for(int i=0;i<x;i++){
    	cin>>a;
    	v.push_back(a);
	}
	int y;
	y=sockMerchant(v.size(), v);
	cout<<y;
}
