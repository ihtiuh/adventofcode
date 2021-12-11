#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    string direction;
    int unit,x=0,y=0,aim=0;
    while(cin>>direction>>unit)
        if(direction=="forward"){
            x+=unit;
            y+=aim*unit;
        }
        else if(direction=="down")
            aim+=unit;
        else if(direction=="up")
            aim-=unit;
    cout<<x*y<<endl;
}
