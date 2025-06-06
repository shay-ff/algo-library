const int N = $0;

vector<int> g[N];
int used[N];

int solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		used[i] = 0;
		g[i].clear();
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	$1
}