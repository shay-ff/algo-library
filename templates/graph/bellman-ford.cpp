#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0;
    vector<tuple<int,int,int>> edges;
    for(int i=0;i<m;i++){ int u,v,w; cin>>u>>v>>w; edges.emplace_back(u,v,w); }
    const long long INF = (1LL<<60);
    vector<long long> dist(n+1, INF); dist[1]=0;
    for(int i=1;i<=n-1;i++){
        for(auto &[u,v,w]: edges) if(dist[u]<INF) dist[v]=min(dist[v], dist[u]+w);
    }
    // optional: detect negative cycle reachable from source
    cout<< (dist[n]==INF? -1 : dist[n]) <<"\n";
    return 0;
}
