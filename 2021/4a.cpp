#include <bits/stdc++.h>
#include <string>
using namespace std;

void markboard(vector<vector<int>> &board, vector<vector<int>> &markerboard, int number){
    for(int i=0; i<5;i++){
        for(int j=0;j<5;j++){
            if(board[i][j]==number){
                markerboard[i][j]=1;
                return;
            }
        }
    }
}

bool checkwinner(vector<vector<int>>  markerboard){
    for(int i=0; i<5;i++){
        bool row=true;
        for(int j=0;j<5;j++){
            if(markerboard[i][j]==0){
                row=false;
                break;
            }
        }
        if (row) return true;
    }
    for(int i=0; i<5;i++){
        bool col=true;
        for(int j=0;j<5;j++){
            if(markerboard[j][i]==0){
                col=false;
                break;
            }
        }
        if (col) return true;
    }
    return false;
}

int main()
{
    string numbersraw;
    vector<int> numbers;
    cin>>numbersraw;
    stringstream  ss(numbersraw);
    string str;
    while (getline(ss, str, ','))
        numbers.push_back(stoi(str));
    vector<vector<vector<int>>> allboards;
    int n;
    while (cin>>n){
        bool newboard=true;
        vector<vector<int>> board(5, vector<int> (5, 0));
        for(int i=0; i<5;i++){
            for(int j=0;j<5;j++){
                if(i!=0 or j!=0){
                    cin>>n;
                }
                board[i][j]=n;
            }
        }
        allboards.push_back(board);
    }

    vector<vector<vector<int>>> markerboards(allboards.size(), vector<vector<int>> (5, vector<int> (5, 0)));
    for(int x=0;numbers.size();x++){
        for(int i=0;i<allboards.size();i++){
            markboard(allboards[i], markerboards[i], numbers[x]);
            if(checkwinner(markerboards[i])){
                int sum=0;
                for(int r=0;r<5;r++){
                    for(int c=0;c<5;c++){
                        if(!markerboards[i][r][c]){
                            sum+=allboards[i][r][c];
                        }
                    }
                }
                cout<<sum*numbers[x]<<endl;
                return 0;
            }

        }

    }
}
