#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

int N=2000;
int main()
{
    vector<int> nums;
    string raw, str;
    cin>>raw;
    stringstream  ss(raw);

    while (getline(ss, str, ','))
        nums.push_back(stoi(str));

    int best=INT_MAX;
    for(int med=0;med<N;med++){
        int score=0;
        for(int i=0;i<nums.size();i++){
            int n = abs(nums[i]-med);
            score += n*(n+1)/2;
        }
        if(score<best)
            best=score;
    }
    cout<<best<<endl;
    return 0;
}
