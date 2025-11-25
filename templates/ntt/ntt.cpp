#include <bits/stdc++.h>
using namespace std;

// Number Theoretic Transform template (mod must be prime of form c*2^k+1)
using ll = long long;
ll modpow(ll a,ll e,ll mod){ ll r=1; while(e){ if(e&1) r=r*a%mod; a=a*a%mod; e>>=1; } return r; }

void ntt(vector<ll> &a, bool invert, ll mod, ll root){ int n=a.size(); for(int i=1,j=0;i<n;i++){ int bit=n>>1; for(; j&bit; bit>>=1) j^=bit; j^=bit; if(i<j) swap(a[i], a[j]); }
    for(int len=2; len<=n; len<<=1){ ll wlen = modpow(root, (mod-1)/len, mod); if(invert) wlen = modpow(wlen, mod-2, mod); for(int i=0;i<n;i+=len){ ll w=1; for(int j=0;j<len/2;j++){ ll u=a[i+j], v=a[i+j+len/2]*w%mod; a[i+j]=(u+v)%mod; a[i+j+len/2]=(u-v+mod)%mod; w=w*wlen%mod; } } }
    if(invert){ ll inv_n = modpow(n, mod-2, mod); for(auto &x: a) x = x*inv_n%mod; }
}

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    // fill mod and primitive root for your modulus
    return 0;
}
