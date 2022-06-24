#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    int n;
    cin>>n;
	vector<int>v;  
    while(cin){
        int x;
        cin>>x;
       if(!cin.fail()) v.push_back(x);
    }
    int a;
    cin>>a;
    v.erase(v.begin()+a);
    int c,b;
    cin>>b>>c;
    v.erase(v.begin()+b,v.begin()+c);
    int size;
    size=v.size();
    cout << size <<endl;
    for(int i=0;i<size;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}

