#include <bits/stdc++.h>
#include <string>
using namespace std;


int getprefix(vector<string> diag, int currentpos){
    string prefix;
    int a=0;
    for (int i=0; i<diag.size();i++){
        if(diag[i][currentpos]=='0')a--;
        else a++;
    }
    return a;
}

vector<string> getnewdiagnostic(vector<string> diag, string prefix){
    vector<string> result;
    for(int i=0; i<diag.size();i++){
        if(diag[i].rfind(prefix,0)==0){
            result.push_back(diag[i]);
        }
    }
    return result;
}

int main()
{
    vector<string> mdiag, ldiag;
    string n;
    while(cin >> n){
        mdiag.push_back(n);
        ldiag.push_back(n);
    }

    string mprefix,lprefix;
    int currentpos=0;
    while(mdiag.size()>1){
        int a=getprefix(mdiag, currentpos++);
        if(a<0) mprefix+='0';
        else mprefix+='1';

        mdiag = getnewdiagnostic(mdiag, mprefix);
    }
    currentpos=0;
    while(ldiag.size()>1){

        int a=getprefix(ldiag, currentpos++);
        if(a<0) lprefix+='1';
        else lprefix+='0';

        ldiag = getnewdiagnostic(ldiag, lprefix);
    }

    cout<<stoull(mdiag[0], 0, 2)*stoull(ldiag[0], 0, 2)<<endl;
    return 0;
}
