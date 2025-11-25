struct DSU {
	vector<int> parent, rank;
	int n;
	DSU(int size) : n(size) {
		parent.resize(n);
		rank.resize(n, 0);
		iota(parent.begin(), parent.end(), 0);
	}
	int find(int a){
		return parent[a] == a ? a : parent[a] = find(parent[a]);
	}
	void join(int a, int b){
		a = find(a);
		b = find(b);
		if(a != b){
			if(rank[a] < rank[b]) swap(a, b);
			parent[b] = a;
			if(rank[a] == rank[b]) rank[a]++;
		}
	}
	bool is_connected(int a, int b){
		return find(a) == find(b);
	}
	int component_size(int a){
		int root = find(a);
		int size = 0;
		for(int i = 0; i < n; i++){
			if(find(i) == root) size++;
		}
		return size;
	}
};