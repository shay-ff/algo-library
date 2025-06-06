struct DSU {
	vector<int> pr;
	int n;

	DSU(int n) : n(n) {
		pr.resize(n);
		iota(pr.begin(), pr.end(), 0);
	}

	inline int findpr(int v) {
		return (v == pr[v] ? v : (pr[v] = findpr(pr[v])));
	}

	inline bool unite(int v, int u) {
		v = findpr(v);
		u = findpr(u);
		if (u == v) {
			return false;
		} else {
			pr[v] = u;
			return true;
		}
	}
};