#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> g;
vector<int> tin, low, vis;
int timer;
vector<pair<int,int>> bridges;

void dfs(int v, int p=-1){ vis[v]=1; tin[v]=low[v]=timer++;
    for(int to: g[v]){
        if(to==p) continue;
        if(vis[to]) low[v]=min(low[v], tin[to]);
        else{ dfs(to, v); low[v]=min(low[v], low[to]); if(low[to]>tin[v]) bridges.emplace_back(v,to); }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(!(cin>>n>>m)) return 0;
    g.assign(n,{}); tin.assign(n,-1); low.assign(n,-1); vis.assign(n,0); timer=0;
    for(int i=0;i<m;i++){ int u,v; cin>>u>>v; g[u].push_back(v); g[v].push_back(u); }
    for(int i=0;i<n;i++) if(!vis[i]) dfs(i);
    for(auto &e: bridges) cout<<e.first<<" "<<e.second<<"\n";
    return 0;
}
