#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key,prio,sz;
    Node *l,*r;
    Node(int key):key(key),prio(rand()),sz(1),l(nullptr),r(nullptr){}
};

int sz(Node* t){ return t? t->sz:0; }
void upd(Node* t){ if(t) t->sz = 1 + sz(t->l) + sz(t->r); }

void split(Node* t,int key, Node*&l, Node*&r){ if(!t){l=r=nullptr; return;} if(key < t->key){ split(t->l,key,l,t->l); r=t; } else { split(t->r,key,t->r,r); l=t; } upd(t); }
Node* merge(Node* a, Node* b){ if(!a || !b) return a? a : b; if(a->prio < b->prio){ a->r = merge(a->r,b); upd(a); return a; } else { b->l = merge(a,b->l); upd(b); return b; } }

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    // basic treap usage example
    Node* root = nullptr;
    // insert 1..5
    for(int i=1;i<=5;i++){ Node *a,*b; split(root,i-1,a,b); root = merge(merge(a, new Node(i)), b); }
    cout<<sz(root)<<"\n";
    return 0;
}
