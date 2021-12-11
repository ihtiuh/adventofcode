#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int N=100;
int d[] = {-1,0,1};
int result = 0;
void flashNeighbor(vector<vector<int>> &mp, int x, int y){
    mp[x][y]=-1;
    result++;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int xd=x+d[i];
            int yd=y+d[j];
            if(xd<0 or xd>=mp.size() or yd<0 or yd>=mp[0].size())
                continue;
            if(mp[xd][yd]!=-1)
                mp[xd][yd]++;
            if(mp[xd][yd]>=10)
                flashNeighbor(mp, xd, yd);
        }
    }
}

int main()
{
    string s;
    vector<vector<int>> mp;
    for(int i=0;cin>>s;i++){
        vector<int> row;
        for(int j=0;j<s.length();j++){
            row.push_back(s[j]-'0');
        }
        mp.push_back(row);
    }
    for(int s=0;s<N;s++){
        for(int i=0;i<mp.size();i++)
            for(int j=0;j<mp[i].size();j++)
                mp[i][j]++;
        for(int i=0;i<mp.size();i++)
            for(int j=0;j<mp[i].size();j++)
                if(mp[i][j]==10)
                    flashNeighbor(mp, i, j);
        for(int i=0;i<mp.size();i++)
            for(int j=0;j<mp[i].size();j++)
                if(mp[i][j]==-1)
                    mp[i][j]=0;
    }
    cout<<result<<endl;

    return 0;
}
