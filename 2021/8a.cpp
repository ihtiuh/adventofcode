#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;

int N=200;
int main()
{
    int result=0;

    for(int i=0;i<N;i++){
        vector<int> signals(10, 0);
        for(int j=0;j<10;j++){
            string s;
            cin>>s;
            if(s.length()==2 || s.length()==4 || s.length()==3 || s.length()==7)
                signals[s.length()] = 1;
        }
        char separator;
        cin>>separator;
        for(int j=0;j<4;j++){
            string s;
            cin>>s;
            if(signals[s.length()])
                result++;
        }
    }
    cout<<result<<endl;
    return 0;
}
