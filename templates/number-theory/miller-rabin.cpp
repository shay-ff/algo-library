#include <bits/stdc++.h>
using namespace std;

using u128 = __uint128_t;
long long modmul(long long a,long long b,long long mod){ return (u128)a*b%mod; }
long long modpow(long long a,long long d,long long mod){ long long r=1; while(d){ if(d&1) r=modmul(r,a,mod); a=modmul(a,a,mod); d>>=1; } return r; }

bool isPrime(long long n){ if(n<2) return false; for(long long p: {2,3,5,7,11,13,17,19,23,29,31,37}){ if(n%p==0) return n==p; }
    long long d=n-1,s=0; while((d&1)==0){ d>>=1; s++; }
    for(long long a: {2,325,9375,28178,450775,9780504,1795265022}){
        if(a%n==0) continue; long long x = modpow(a,d,n); if(x==1 || x==n-1) continue; bool comp=true; for(int r=1;r<s;r++){ x=modmul(x,x,n); if(x==n-1){ comp=false; break; } } if(comp) return false; }
    return true;
}

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n; if(!(cin>>n)) return 0; cout<<(isPrime(n)?"PRIME":"COMPOSITE")<<"\n"; return 0; }
