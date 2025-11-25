#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0;
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=0;i<m;i++){ int u,v,w; cin>>u>>v>>w; g[u].push_back({w,v}); g[v].push_back({w,u}); }
    vector<int> vis(n+1,0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1}); long long cost=0;
    while(!pq.empty()){
        auto [w,u]=pq.top(); pq.pop(); if(vis[u]) continue; vis[u]=1; cost+=w;
        for(auto &e: g[u]) if(!vis[e.second]) pq.push(e);
    }
    cout<<cost<<"\n";
    return 0;
}
