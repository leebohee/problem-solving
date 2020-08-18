#include <cstdio>
#include <vector>
#include <algorithm>

#define MAX_N 1000

using namespace std;

class DisjointSet {
public:
	DisjointSet(int n_) {
		n = n_;
		for (int i = 1; i <= n; i++)
		{
			parent[i] = i;
		}
	};

	bool same_set(int u, int v) {
		if (find(u) == find(v)) return true;
		else return false;
	}

	int find(int u) {
		if (parent[u] == u) return u;
		else return parent[u] = find(parent[u]);
	}

	void unify(int u, int v) {
		int rootU = find(u);
		int rootV = find(v);
		parent[rootV] = rootU;
	}

private:
	int parent[MAX_N + 1];
	int n;
};

struct edge{
	int src;
	int dest;
	int cost;
	edge(int s, int d, int c) : src(s), dest(d), cost(c) {};
	bool operator<(const struct edge& e) const {
		return this->cost < e.cost;
	}
};

int N, M;
vector<edge> edges;

int mst() {
	int cost_sum = 0, selected = 0;
	
	sort(edges.begin(), edges.end());

	DisjointSet ds(N);
	for (const edge& e : edges) {
		if (ds.same_set(e.src, e.dest)) continue;
		ds.unify(e.src, e.dest);
		cost_sum += e.cost;
		if (++selected == N - 1) break;
	}

	return cost_sum;
}

int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edges.emplace_back(a, b, c);
	}
	printf("%d", mst());
	return 0;
}