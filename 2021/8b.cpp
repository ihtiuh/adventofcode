#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <map>
using namespace std;

string reverseFind(map<string, int> mp, int value){
    for (auto it = mp.begin(); it != mp.end(); ++it)
        if (it->second == value)
            return it->first;
}

bool exist(string super, string sub){
    for(int i=0;i<sub.length();i++)
        if(super.find(sub[i])==string::npos)
            return false;
    return true;
}

int N=200;
int main()
{
    int result=0;

    for(int i=0;i<N;i++){
        map<string, int> mp;
        for(int j=0;j<10;j++){
            string s;
            cin>>s;
            sort(s.begin(),s.end());
            if(s.length()==2)
                mp.insert({s,1});
            else if(s.length()==4)
                mp.insert({s,4});
            else if(s.length()==3)
                mp.insert({s,7});
            else if(s.length()==7)
                mp.insert({s,8});
            else
                mp.insert({s,-1});
        }
        for (auto itr = mp.begin();itr != mp.end(); ++itr)
            if((itr->first).length()==5){
                string one=reverseFind(mp, 1);
                if(exist(itr->first, one))
                    itr->second=3;
            }

        for (auto itr = mp.begin();itr != mp.end(); ++itr)
            if((itr->first).length()==6){
                string three=reverseFind(mp, 3);
                if(exist(itr->first, three))
                    itr->second=9;
            }

        for (auto itr = mp.begin();itr != mp.end(); ++itr)
            if((itr->first).length()==6 && itr->second==-1){
                string s=reverseFind(mp, 1);
                if(exist(itr->first, s))
                    itr->second=0;
            }

        for (auto itr = mp.begin();itr != mp.end(); ++itr)
            if((itr->first).length()==6 && itr->second==-1)
                itr->second=6;

        for (auto itr = mp.begin();itr != mp.end(); ++itr)
            if((itr->first).length()==5 && itr->second==-1){
                string s=reverseFind(mp, 1);
                string n=reverseFind(mp, 6);
                if(n.find(s[0])!=string::npos)
                    if(exist(itr->first, string(1, s[0])))
                        itr->second=5;
                    else
                        itr->second=2;
                else
                    if(exist(itr->first, string(1, s[0])))
                        itr->second=2;
                    else
                        itr->second=5;
            }

        char separator;
        cin>>separator;
        int number=0;
        for(int j=0;j<4;j++){
            string s;
            cin>>s;
            sort(s.begin(),s.end());
            number += (mp.find(s)->second)*pow(10, 3-j);
        }
        result+=number;
    }
    cout<<result<<endl;
    return 0;
}
