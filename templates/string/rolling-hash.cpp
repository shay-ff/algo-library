#include <bits/stdc++.h>
using namespace std;

struct RollingHash{
    using ull = unsigned long long;
    ull base; vector<ull> h, p;
    RollingHash(const string &s, ull base=1315423911ULL): base(base){ int n=(int)s.size(); h.assign(n+1,0); p.assign(n+1,1); for(int i=0;i<n;i++){ h[i+1]=h[i]*base + (unsigned char)s[i]; p[i+1]=p[i]*base; } }
    // get hash for substring [l, r) 0-indexed
    ull get(int l,int r) const { return h[r] - h[l]*p[r-l]; }
};

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    string s; if(!(cin>>s)) return 0; RollingHash rh(s);
    // example: calling rh.get(l,r) returns hash for s[l..r-1]
    return 0;
}
