#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <map>
using namespace std;

map<string, vector<string>> mp;
vector<vector<string>> paths;
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
    paths.push_back(start);
    while(paths.size()){
        vector<string> path = paths.back();
        paths.pop_back();

        for(auto n : mp[path.back()]){
            if(n=="end"){
                result++;
                continue;
            }
            if(islower(n[0]))
				if (count(path.begin(), path.end(), n)>0)
					continue;
            vector<string> newpath = path;
            newpath.push_back(n);
            paths.push_back(newpath);
        }
    }
    cout<<result<<endl;

    return 0;
}
