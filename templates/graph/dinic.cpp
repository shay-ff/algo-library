#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct Edge{int to; long long cap; int rev;};
    int N; vector<vector<Edge>> g; vector<int> level, it;
    Dinic(int n):N(n),g(n),level(n),it(n){}
    void addEdge(int u,int v,long long c){ g[u].push_back({v,c,(int)g[v].size()}); g[v].push_back({u,0,(int)g[u].size()-1}); }
    bool bfs(int s,int t){ fill(level.begin(), level.end(), -1); queue<int>q; level[s]=0; q.push(s); while(!q.empty()){int v=q.front();q.pop(); for(auto &e:g[v]) if(e.cap>0 && level[e.to]<0){ level[e.to]=level[v]+1; q.push(e.to);} } return level[t]>=0; }
    long long dfs(int v,int t,long long f){ if(v==t) return f; for(int &i=it[v]; i<(int)g[v].size(); ++i){ Edge &e=g[v][i]; if(e.cap>0 && level[e.to]==level[v]+1){ long long ret=dfs(e.to,t,min(f,e.cap)); if(ret>0){ e.cap-=ret; g[e.to][e.rev].cap+=ret; return ret; } } } return 0; }
    long long maxflow(int s,int t){ long long flow=0; while(bfs(s,t)){ fill(it.begin(), it.end(), 0); while(true){ long long f=dfs(s,t,LLONG_MAX); if(!f) break; flow+=f; } } return flow; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; if(!(cin>>n>>m)) return 0;
    Dinic D(n+5);
    int s,t; cin>>s>>t;
    for(int i=0;i<m;i++){ int u,v; long long c; cin>>u>>v>>c; D.addEdge(u,v,c); }
    cout<<D.maxflow(s,t)<<"\n";
    return 0;
}
