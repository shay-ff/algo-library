#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n; vector<long long> st, lazy;
    SegTree(int n):n(n),st(4*n,0),lazy(4*n,0){}
    void push(int p,int l,int r){ if(lazy[p]){ st[p]+=lazy[p]*(r-l+1); if(l!=r){ lazy[2*p]+=lazy[p]; lazy[2*p+1]+=lazy[p]; } lazy[p]=0; } }
    void update(int p,int l,int r,int ql,int qr,long long val){ push(p,l,r); if(ql>r||qr<l) return; if(ql<=l&&r<=qr){ lazy[p]+=val; push(p,l,r); return; } int m=(l+r)/2; update(2*p,l,m,ql,qr,val); update(2*p+1,m+1,r,ql,qr,val); st[p]=st[2*p]+st[2*p+1]; }
    long long query(int p,int l,int r,int ql,int qr){ push(p,l,r); if(ql>r||qr<l) return 0; if(ql<=l&&r<=qr) return st[p]; int m=(l+r)/2; return query(2*p,l,m,ql,qr)+query(2*p+1,m+1,r,ql,qr); }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q; if(!(cin>>n>>q)) return 0;
    SegTree st(n);
    while(q--){ int type; cin>>type; if(type==1){ int l,r; long long v; cin>>l>>r>>v; st.update(1,1,n,l,r,v);} else { int l,r; cin>>l>>r; cout<<st.query(1,1,n,l,r)<<"\n"; } }
    return 0;
}
