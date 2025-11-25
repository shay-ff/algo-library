#include <bits/stdc++.h>
using namespace std;

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0; vector<int> a(n); for(int i=0;i<n;i++) cin>>a[i];
    int ALL = 1<<n; vector<int> dp(ALL, 0);
    for(int mask=1; mask<ALL; ++mask){ int lb = __builtin_ctz(mask); dp[mask] = dp[mask ^ (1<<lb)] + a[lb]; }
    // dp[mask] stores sum of selected elements
    cout<<"Computed sums for all subsets\n";
    return 0;
}
