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
    {')',3},
    {'}',1197},
    {'>',25137},
    {']',57},
};
int main()
{
    int result=0;
    string s;
    while(cin>>s){
        string ns="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='<' or s[i]=='[')
                ns+=s[i];
            else
                if(s[i]!=mp[ns[ns.length()-1]]){
                    result+=score[s[i]];
                    break;
                }
                else
                    ns.pop_back();
        }
    }
    cout<<result<<endl;

    return 0;
}
