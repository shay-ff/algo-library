#include <bits/stdc++.h>
using namespace std;

// Generic binary search template for monotonic predicate
long long bs_long(long long lo,long long hi, function<bool(long long)> pred){ while(lo<hi){ long long mid = lo + (hi-lo)/2; if(pred(mid)) hi = mid; else lo = mid+1; } return lo; }

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    // Example: find smallest x with x^2 >= n
    long long n; if(!(cin>>n)) return 0; auto pred = [&](long long x){ return x*x >= n; };
    cout<<bs_long(0, (long long)2e9, pred)<<"\n";
    return 0; }
