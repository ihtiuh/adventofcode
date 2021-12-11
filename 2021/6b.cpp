#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;

int N=256;
int main()
{
    string numbersraw;
    cin>>numbersraw;
    stringstream  ss(numbersraw);
    string str;
    long long fishmap[9]={0};
    while (getline(ss, str, ','))
        fishmap[stoi(str)]++;

    for(int i=0;i<N;i++){
        long long rotatefish=0;
        for(int j=0;j<9;j++){
            if(j==0)
                rotatefish+=fishmap[0];
            else
                fishmap[j-1] = fishmap[j];
        }
        fishmap[8]=rotatefish;
        fishmap[6]+=rotatefish;
    }
    long long sum=0;
    for(int i=0;i<9;i++)
        sum+=fishmap[i];
    cout<<sum<<endl;
    return 0;
}
