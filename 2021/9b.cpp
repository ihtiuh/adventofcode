#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int N=102, M=102;

void dfs(int x, int y, vector<vector<int>> &mp, int &basinSize){
    if(mp[x][y]==-1) return;
    else{
        basinSize++;
        mp[x][y]=-1;
    }
    if(mp[x][y+1]!=9) dfs(x, y+1, mp, basinSize);
    if(mp[x][y-1]!=9) dfs(x, y-1, mp, basinSize);
    if(mp[x+1][y]!=9) dfs(x+1, y, mp, basinSize);
    if(mp[x-1][y]!=9) dfs(x-1, y, mp, basinSize);
}

int main()
{
    vector<vector<int>> mp(N, vector<int>(M, 9));
    for(int i=1;i<N-1;i++){
        string s;
        cin>>s;
        for(int j=1;j<M-1;j++)
            mp[i][j]=s[j-1]-'0';
    }

    vector<int> basinSizes;
    for(int i=1;i<N-1;i++){
        for(int j=1;j<M-1;j++){
            if(mp[i][j]!=-1 && mp[i][j]!=9){
                int basinSize=0;
                dfs(i,j,mp, basinSize);
                basinSizes.push_back(basinSize);
            }
        }
    }
    sort(basinSizes.begin(), basinSizes.end());
    int bs = basinSizes.size();
    cout<<basinSizes[bs-3]*basinSizes[bs-2]*basinSizes[bs-1]<<endl;

    return 0;
}
