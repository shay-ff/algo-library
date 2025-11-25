#include <bits/stdc++.h>
using namespace std;

using u128 = __uint128_t;
long long modmul(long long a,long long b,long long mod){ return (u128)a*b%mod; }
long long modpow(long long a,long long d,long long mod){ long long r=1; while(d){ if(d&1) r=modmul(r,a,mod); a=modmul(a,a,mod); d>>=1; } return r; }

long long absll(long long x){ return x<0? -x: x; }
long long f(long long x,long long c,long long mod){ return (modmul(x,x,mod) + c) % mod; }

long long pollard(long long n){ if(n%2==0) return 2; if(n%3==0) return 3; long long c = rand()%n +1; long long x = rand()%n, y=x, d=1;
    while(d==1){ x = f(x,c,n); y = f(f(y,c,n),c,n); d = gcd(absll(x-y), n); if(d==n) return pollard(n); }
    return d;
}

void factor(long long n, vector<long long>& res){ if(n==1) return; if(n<1e6){ for(long long p=2;p*p<=n;p++) while(n%p==0){ res.push_back(p); n/=p; } if(n>1) res.push_back(n); return; } if([&](){ // simple MR
    using u128 = __uint128_t; auto isPrime=[&](long long x)->bool{ if(x<2) return false; for(long long p: {2,3,5,7,11,13,17,19,23,29}) if(x%p==0) return x==p; long long d=x-1,s=0; while(!(d&1)){d>>=1;s++;} for(long long a: {2,325,9375,28178,450775,9780504,1795265022}){ if(a%x==0) continue; long long r=1, base=a% x, dd=d; while(dd){ if(dd&1) r=(u128)r*base%x; base=(u128)base*base%x; dd>>=1; } if(r==1||r==x-1) continue; bool comp=true; for(int i=1;i<s;i++){ r=(u128)r*r % x; if(r==x-1){ comp=false; break;} } if(comp) return false;} return true; }; return isPrime(n); }()) { res.push_back(n); return; } long long d = pollard(n); factor(d,res); factor(n/d, res); }

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    long long n; if(!(cin>>n)) return 0; vector<long long> f; factor(n,f); sort(f.begin(), f.end()); for(auto p: f) cout<<p<<" "; cout<<"\n"; return 0; }
