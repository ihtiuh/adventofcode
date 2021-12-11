#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,psum=INT_MAX,nsum=0,result=0, first=0, second=0, third;
    cin>>first;
    cin>>second;
    while(cin>>n){
      nsum=first+second+n;
      if(nsum>psum)
        result++;
      first=second;
      second=n;
      psum=nsum;
    }
    cout<<result<<endl;
    return 0;
}
