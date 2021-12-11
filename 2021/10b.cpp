#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <map>
using namespace std;

map<char, char> mp{
    {'(',')'},
    {'{','}'},
    {'<','>'},
    {'[',']'},
};
map<char, int> score{
    {')',1},
    {'}',3},
    {'>',4},
    {']',2},
};
int main()
{
    vector<long long> r;
    string s;
    while(cin>>s){
        string ns="";
        bool con=false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='<' or s[i]=='[')
                ns+=s[i];
            else
                if(s[i]!=mp[ns[ns.length()-1]]){
                    con=true;
                    break;
                }
                else
                    ns.pop_back();
        }
        long long result=0;
        while(!con and ns.length()){
            result*=5;
            result+=score[mp[ns[ns.length()-1]]];
            ns.pop_back();
        }
        if(!con)
            r.push_back(result);
    }

    sort(r.begin(),r.end());
    cout<<r[(r.size()-1)/2]<<endl;

    return 0;
}
