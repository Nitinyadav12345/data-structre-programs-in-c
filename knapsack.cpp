#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int max(int a,int b){
    return (a>b)?a:b;
}
int knapsack(int m,int wt[],int pr[],int n ){
    int k[100][100];
    for(int i=0;i<=n;i++){
        for(int w=0;w<=m;w++){
            if(w==0||i==0)
            k[i][w]=0;
            else if(wt[i]<=w)
            k[i][w]=max(pr[i]+k[i-1][w-wt[i]],k[i-1][w]);
            else k[i][w]=k[i-1][w];
        }
    }
    return k[n][m];
}
int main()
{   
    int m,n;
    cout<<"enter the no. of products and max bag size \n";
    cin>>m;
    cin>>n;
    int* pr=new int[n+1];
    int* wt=new int[n+1];
    pr[0]=0;wt[0]=0;
    for(int i=1;i<n;i++){
    	cout<<"enter the element weigth and profit \n";
    	cin>>wt[i]>>pr[i];
	}
    cout << knapsack(m,wt,pr,n) <<endl;

    return 0;
}

