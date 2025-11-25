// LCA using Binary Lifting
const int MAXN = 1e5, LOG = 17;
vector<int> adj[MAXN];
int up[MAXN][LOG], depth[MAXN];

void dfs(int v, int p) {
  up[v][0] = p;
  for (int i = 1; i < LOG; ++i)
    up[v][i] = up[up[v][i - 1]][i - 1];
  for (int u : adj[v])
    if (u != p) {
      depth[u] = depth[v] + 1;
      dfs(u, v);
    }
}

int lca(int u, int v) {
  if (depth[u] < depth[v])
    swap(u, v);
  for (int i = LOG - 1; i >= 0; --i)
    if (depth[u] - (1 << i) >= depth[v])
      u = up[u][i];
  if (u == v)
    return u;
  for (int i = LOG - 1; i >= 0; --i)
    if (up[u][i] != up[v][i])
      u = up[u][i], v = up[v][i];
  return up[u][0];
}