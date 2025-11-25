#include <bits/stdc++.h>
using namespace std;

struct HLD {
    int n; vector<vector<int>> g; vector<int> sz, parent, depth, heavy, head, pos; int cur;
    HLD(int n):n(n),g(n),sz(n,0),parent(n,-1),depth(n,0),heavy(n,-1),head(n),pos(n),cur(0){}
    void addEdge(int u,int v){ g[u].push_back(v); g[v].push_back(u); }
    int dfs(int v,int p){ parent[v]=p; sz[v]=1; int maxsz=0; for(int c: g[v]) if(c!=p){ depth[c]=depth[v]+1; int s=dfs(c,v); sz[v]+=s; if(s>maxsz){ maxsz=s; heavy[v]=c; } } return sz[v]; }
    void decompose(int v,int h){ head[v]=h; pos[v]=cur++; if(heavy[v]!=-1) decompose(heavy[v], h); for(int c: g[v]) if(c!=parent[v] && c!=heavy[v]) decompose(c,c); }
    void build(int root=0){ dfs(root,-1); decompose(root,root); }
};

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0; HLD h(n);
    for(int i=0;i<m;i++){ int u,v; cin>>u>>v; h.addEdge(u,v); }
    h.build(0);
    // use h.pos and segment tree on positions to answer path queries
    return 0;
}
