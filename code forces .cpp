#include <bits/stdc++.h>

using namespace std;

bool check(double N)
{
    int X = N;

    double temp2 = N - X;

    if (temp2 > 0) {
        return false;
    }
    return true;
}

int main()
{
   int t;
   cin>>t;
   while(t--){
       double x,y;
       cin>>x>>y;
       double z;
       z=y/x;

      if(check(z)){
          cout<<"1 "<<int(y/x)<<endl;

      }
      else{
          cout<<"0 0"<<endl;
      }
   }
   return 0;
}
