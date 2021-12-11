#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    string n;
    int a[9999]={1};
    for(int x=0;cin >> n;x++){
        for(int i=0; i<n.length(); i++){
            if(n[i]=='0')
                a[i]--;
            else
                a[i]++;
        }
    }
    string mcn="", lcn="";
    for(int i=0;i<n.length();i++){
        if(a[i]<0){
            mcn+='0';
            lcn+='1';
        }
        else{
            mcn+='1';
            lcn+='0';
        }
    }

    cout<<stoull(mcn, 0, 2)*stoull(lcn, 0, 2)<<endl;

    return 0;
}
