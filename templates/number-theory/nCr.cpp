#include <bits/stdc++.h>
using namespace std;

struct Comb {
    int N; long long mod; vector<long long> fact, ifact;
    Comb(int N, long long mod):N(N),mod(mod),fact(N+1),ifact(N+1){ fact[0]=1; for(int i=1;i<=N;i++) fact[i]=fact[i-1]*i%mod; ifact[N]=[](long long x,long long m){ long long r=1; long long e=m-2; while(e){ if(e&1) r=r*x% m; x=x*x% m; e>>=1;} return r; }(fact[N],mod); for(int i=N;i>0;i--) ifact[i-1]=ifact[i]*i%mod; }
    long long C(int n,int k){ if(k<0||k>n) return 0; return fact[n]*ifact[k]%mod*ifact[n-k]%mod; }
};

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,k; long long mod; if(!(cin>>n>>k>>mod)) return 0; Comb c(n,mod); cout<<c.C(n,k)<<"\n"; return 0; }
