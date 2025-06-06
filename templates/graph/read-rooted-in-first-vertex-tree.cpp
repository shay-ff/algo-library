const int N = $0;

vector<int> g[N];
int used[N], pr[N];

int solve() {
	int n;
	if (!(cin >> n)) {
		return 1;
	}
	for (int i = 0; i < n; i++) {
		used[i] = 0;
		g[i].clear();
	}
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		p--;
		g[p].push_back(i);
		pr[i] = p;
	}
	$1
	return 1;
}