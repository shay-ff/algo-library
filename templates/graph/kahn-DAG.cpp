// Kahn's Algorithm for Topological Sort
vector<int> toposort(int n, vector<vector<int>>& adj) {
    vector<int> in(n), res;
    for (auto& edges : adj)
        for (int v : edges) in[v]++;
    queue<int> q;
    for (int i = 0; i < n; ++i) if (!in[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        res.push_back(u);
        for (int v : adj[u])
            if (--in[v] == 0) q.push(v);
    }
    return res;
}