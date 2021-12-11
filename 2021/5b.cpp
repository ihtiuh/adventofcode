#include <bits/stdc++.h>
#include <string>
#include <cmath> 
using namespace std;

int N=1000;
int main()
{
    vector<vector<int>> map(N, vector<int> (N, 0));

    int x1=0,y1=0,x2=0,y2=0;
    char comma=',';
    string garbage;

    while (cin >> x1 >> comma >> y1 >> garbage >> x2 >> comma >> y2){
        int xd=x1==x2?0:x1<x2?1:-1;
        int yd=y1==y2?0:y1<y2?1:-1;
        int xe=abs(x1-x2);
        int ye=abs(y1-y2);
        int d=xe?xe:ye;

        for (int i=0;i<=d;i++){
            map[x1][y1]++;
            x1+=xd;
            y1+=yd;
        }
    }

    int result=0;
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map.size();j++){
            if(map[i][j]>=2){
                result+=1;
            }
        }
    }
    cout<<result<<endl;
    return 0;
}
