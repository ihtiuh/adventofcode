#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int N=102, M=102;
int main()
{
    int result=0;
    vector<vector<int>> a(N, vector<int>(M, 9));
    for(int i=1;i<N-1;i++){
        string s;
        cin>>s;
        for(int j=1;j<M-1;j++)
            a[i][j]=s[j-1]-'0';
    }

    vector<int> lowest;
    for(int i=1;i<N-1;i++){
        for(int j=1;j<M-1;j++){
            if(a[i][j]>=a[i+1][j] or a[i][j]>=a[i-1][j] or a[i][j]>=a[i][j+1] or a[i][j]>=a[i][j-1])
                continue;
            result+=a[i][j]+1;
        }
    }
    cout<<result<<endl;

    return 0;
}
