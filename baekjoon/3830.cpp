#include <iostream>
#include <vector>

#define MAX_N 100000

using namespace std;

struct edge {
	int v;
	int weight;
	edge(int v_, int w_) : v(v_), weight(w_) {};
};

int N, M;
vector<edge> adj[MAX_N + 1];

int parent[MAX_N + 1];
long long cost[MAX_N + 1];

int find(int u) {
	if (parent[u] == u) return u;
	else {
		int prev_root = parent[u];
		parent[u] = find(parent[u]);
		cost[u] += cost[prev_root];
		return parent[u];
	}
}

bool same_set(int u, int v) {
	if (find(u) == find(v)) return true;
	else return false;
}

void measure(int u, int v, int w) {
	if (u > v) {
		swap(u, v);
		w *= -1;
	}
	int rootU = find(u);
	int rootV = find(v);
	parent[rootV] = rootU;
	cost[rootV] = cost[u] - w - cost[v];
}

void query(int src, int dest) {
	if (!same_set(src, dest)) cout << "UNKNOWN\n";
	else cout << cost[src] - cost[dest] << '\n';
}

int main() {
	freopen("input.txt", "r", stdin);
	char op;
	int a, b, w;

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		for (int i = 1; i <= N; i++) {
			adj[i].clear();
			parent[i] = i;
			cost[i] = 0;
		}
		for (int i = 0; i < M; i++) {
			cin >> op;
			if (op == '!') {
				cin >> a >> b >> w;
				measure(a, b, w);
			}
			else if (op == '?') {
				cin >> a >> b;
				query(a, b);
			}
		}
	}
	return 0;
}