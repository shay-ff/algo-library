#include <bits/stdc++.h>
using namespace std;

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0; vector<long long> a(n); for(int i=0;i<n;i++) cin>>a[i];
    long long best = LLONG_MIN, cur = 0;
    for(auto x: a){ cur = max(x, cur + x); best = max(best, cur); }
    cout<<best<<"\n";
    return 0;
}
