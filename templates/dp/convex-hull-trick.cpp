#include <bits/stdc++.h>
using namespace std;

// Li Chao tree (for lines of form y = m*x + b)
struct LiChao {
    struct Line{ long long m,b; Line(long long _m=0,long long _b=LLONG_MAX):m(_m),b(_b){} long long eval(long long x) const{return m*x + b;} };
    struct Node{ Line ln; Node *l,*r; Node(Line v):ln(v),l(nullptr),r(nullptr){} };
    Node* root; long long L,R;
    LiChao(long long L, long long R):root(nullptr),L(L),R(R){}
    void add_line(Line nw, Node*&v, long long l, long long r){ if(!v){ v=new Node(nw); return; } long long mid=(l+r)/2; bool lef = nw.eval(l) < v->ln.eval(l); bool m = nw.eval(mid) < v->ln.eval(mid); if(m) swap(nw, v->ln); if(r-l==0) return; if(lef != m) add_line(nw, v->l, l, mid); else add_line(nw, v->r, mid+1, r); }
    void add_line(long long m,long long b){ Line ln(m,b); add_line(ln, root, L, R); }
    long long query(long long x, Node* v, long long l, long long r){ if(!v) return LLONG_MAX; long long res = v->ln.eval(x); if(l==r) return res; long long mid=(l+r)/2; if(x<=mid) return min(res, query(x, v->l, l, mid)); else return min(res, query(x, v->r, mid+1, r)); }
    long long query(long long x){ return query(x, root, L, R); }
};

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    // usage: LiChao cht(xmin, xmax); cht.add_line(m,b); cht.query(x);
    return 0;
}
