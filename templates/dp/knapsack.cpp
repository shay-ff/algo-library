#include <bits/stdc++.h>
using namespace std;

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,W; if(!(cin>>n>>W)) return 0; vector<int> w(n), v(n); for(int i=0;i<n;i++) cin>>w[i]>>v[i];
    vector<long long> dp(W+1, 0);
    for(int i=0;i<n;i++) for(int j=W;j>=w[i];j--) dp[j]=max(dp[j], dp[j-w[i]] + v[i]);
    cout<<*max_element(dp.begin(), dp.end())<<"\n";
    return 0; }
