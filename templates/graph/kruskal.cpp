#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> p, r;
    DSU(int n): n(n), p(n+1), r(n+1,0){ iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b){ a=find(a); b=find(b); if(a==b) return false; if(r[a]<r[b]) swap(a,b); p[b]=a; if(r[a]==r[b]) r[a]++; return true; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Input: n m
    // then m edges: u v w
    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<tuple<int,int,int>> edges;
    for(int i=0;i<m;i++){ int u,v,w; cin>>u>>v>>w; edges.emplace_back(w,u,v); }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long cost = 0;
    vector<pair<int,int>> mst;
    for(auto &e: edges){ int w,u,v; tie(w,u,v)=e; if(dsu.unite(u,v)){ cost += w; mst.emplace_back(u,v); } }
    cout << cost << "\n";
    return 0;
}
