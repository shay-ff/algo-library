#include <bits/stdc++.h>
using namespace std;

struct Node{ long long val; Node *l,*r; Node(long long v=0):val(v),l(nullptr),r(nullptr){} };

Node* build(int tl,int tr){ Node* node=new Node(); if(tl==tr) return node; int tm=(tl+tr)/2; node->l=build(tl,tm); node->r=build(tm+1,tr); return node; }
Node* update(Node* prev,int tl,int tr,int pos,long long val){ Node* node=new Node(); *node = *prev; if(tl==tr){ node->val += val; return node; } int tm=(tl+tr)/2; if(pos<=tm) node->l = update(prev->l,tl,tm,pos,val); else node->r = update(prev->r,tm+1,tr,pos,val); node->val = node->l->val + node->r->val; return node; }
long long query(Node* node,int tl,int tr,int l,int r){ if(r<tl||tr<l) return 0; if(l<=tl&&tr<=r) return node->val; int tm=(tl+tr)/2; return query(node->l,tl,tm,l,r)+query(node->r,tm+1,tr,l,r); }

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,q; if(!(cin>>n>>q)) return 0; vector<Node*> roots; roots.push_back(build(1,n));
    while(q--){ int type; cin>>type; if(type==1){ int pos; long long v; cin>>pos>>v; roots.push_back(update(roots.back(),1,n,pos,v)); } else { int ver,l,r; cin>>ver>>l>>r; cout<<query(roots[ver],1,n,l,r)<<"\n"; } }
    return 0; }
