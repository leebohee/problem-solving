#include <cstdio>
#include <vector>
#include <queue>

#define MAX_N 500

using namespace std;

int N;
int hours[MAX_N + 1];
int in_degree[MAX_N + 1];
int result[MAX_N + 1];
vector<int> adj[MAX_N + 1];

void solution() {
	queue<pair<int, int> > q; // (vertex, hours)
	for (int i = 1; i <= N; i++)
	{
		if (in_degree[i] == 0) q.emplace(i, hours[i]);
	}

	while (!q.empty()) {
		pair<int, int>& p = q.front();
		int u = p.first;
		int h = p.second;
		result[u] = h;
		for (int v: adj[u])
		{
			in_degree[v]--;
			result[v] = max(result[v], h + hours[v]);
			if (in_degree[v] == 0) {
				q.emplace(v, result[v]);
			}
		}
		q.pop();
	}

}

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &hours[i]);
		while (true) {
			int n;
			scanf("%d", &n);
			if (n == -1) break;
			in_degree[i]++;
			adj[n].push_back(i);
		}
	}

	solution();
	for (int i = 1; i <= N; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}