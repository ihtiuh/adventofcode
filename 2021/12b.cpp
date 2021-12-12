#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <map>
using namespace std;

map<string, vector<string>> mp;
vector<tuple<vector<string>,bool>> paths;
int result = 0;

int main()
{
    string s;
    while(cin>>s){
        stringstream  ss(s);
        string first, second;
        getline(ss, first, '-');
        getline(ss, second, '\n');
        mp[first].push_back(second);
        mp[second].push_back(first);
    }

    vector<string> start{"start"};
    paths.push_back(make_tuple(start,false));
    while(paths.size()){
        tuple<vector<string>, bool> path = paths.back();
        paths.pop_back();
        vector<string> p = get<0>(path);
        bool twiceAlready = get<1>(path);

        for(auto n : mp[p.back()]){
            bool gotTwice = false;
            if(n=="end"){
                result++;
                continue;
            }
            if(islower(n[0]))
                if(count(p.begin(), p.end(), n)>0){
                    if(twiceAlready or n=="start")
                        continue;
                    if(!twiceAlready)
                        gotTwice = true;
                }
            vector<string> np = p;
            np.push_back(n);
            paths.push_back(make_tuple(np, twiceAlready or gotTwice));
        }

    }
    cout<<result<<endl;

    return 0;
}
