#include <bits/stdc++.h>
using namespace std;

struct TarjanSCC {
    int n, timer=0, comp_cnt=0;
    vector<int> disc, low, st_stack, instack, comp;
    vector<vector<int>> g;
    TarjanSCC(int n):n(n),disc(n,-1),low(n),instack(n,0),comp(n,-1),g(n){}
    void addEdge(int u,int v){ g[u].push_back(v); }
    void dfs(int u){ disc[u]=low[u]=timer++; st_stack.push_back(u); instack[u]=1;
        for(int v: g[u]){
            if(disc[v]==-1) dfs(v), low[u]=min(low[u], low[v]);
            else if(instack[v]) low[u]=min(low[u], disc[v]);
        }
        if(low[u]==disc[u]){
            while(true){ int v=st_stack.back(); st_stack.pop_back(); instack[v]=0; comp[v]=comp_cnt; if(v==u) break; } comp_cnt++; }
    }
    void run(){ for(int i=0;i<n;i++) if(disc[i]==-1) dfs(i); }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0;
    TarjanSCC T(n);
    for(int i=0;i<m;i++){ int u,v; cin>>u>>v; T.addEdge(u,v); }
    T.run();
    // comp id available in T.comp
    return 0;
}
