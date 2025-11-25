#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    const long long INF = 1e15;
    vector<vector<long long>> d(n, vector<long long>(n, INF));
    for(int i=0;i<n;i++) d[i][i]=0;
    int m; cin>>m;
    for(int i=0;i<m;i++){ int u,v; long long w; cin>>u>>v>>w; --u;--v; d[u][v]=min(d[u][v], w); }
    for(int k=0;k<n;k++) for(int i=0;i<n;i++) if(d[i][k]<INF) for(int j=0;j<n;j++) d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
    // print matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<(d[i][j]==INF? -1 : d[i][j])<<" ";
        cout<<"\n";
    }
    return 0;
}
