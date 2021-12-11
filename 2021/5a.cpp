#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;

int N=1000;
int main()
{
    int x1, y1, x2, y2;
    vector<vector<int>> map(N, vector<int> (N, 0));
    string gar;
    char comma;
    while(cin>>x1>>comma>>y1>>gar>>x2>>comma>>y2){
        if(x1==x2){
            if(y1<y2)
                for(int y=y1; y<=y2; y++)
                        map[x1][y]+=1;
            if(y1>y2)
                for(int y=y2; y<=y1; y++)
                        map[x1][y]+=1;
        }
        else if(y1==y2){
            if(x1<x2)
                for(int x=x1; x<=x2; x++)
                        map[x][y1]+=1;
            if(x1>x2)
                for(int x=x2; x<=x1; x++)
                        map[x][y1]+=1;
        }
        else{
            if(x1==y1 and x2==y2){
                for(int x=x1, y=y1;x<=x2 or y<=y2;x++,y++){
                    map[x][y]+=1;
                }
            }
            else if(x1+y1==x2+y2){
                for(int x=0;x<N;x++){
                    for(int y=0;y<N;y++){
                        if(x+y==x1+y1 and x+y==x2+y2){
                            map[x][y]+=1;
                        }
                    }
                }
            }
            else{
                if(x1<x2 && y1<y2){
                    for(int x=x1, y=y1;x<=x2 or y<=y2;x++,y++){
                        map[x][y]+=1;
                    }
                }
                else if(x2<x1 && y2<y1){
                    for(int x=x2, y=y2;x<=x1 or y<=y1;x++,y++){
                        map[x][y]+=1;
                    }
                }
            }

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
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<map[j][i];
        }
        cout<<endl;
    }
    cout<< result<<endl;
    return 0;
}
