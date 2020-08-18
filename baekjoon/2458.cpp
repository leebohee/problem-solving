#include <cstdio>
#include <vector>
#include <queue>

#define MAX_N 500

using namespace std;

int N, M;

// 나보다 큰 사람 수: 나로부터 갈 수 있는 노드 개수
// 나보다 작은 사람 수: 모든 간선을 뒤집은 후, 나로부터 갈 수 있는 노드 개수
vector<int> adj[MAX_N + 1];
vector<int> adj_rev[MAX_N + 1];

int count(int start, bool dir=true) {
	bool visit[MAX_N + 1] = { false, };
	queue<int> q;
	int n = -1;

	q.push(start);
	if (dir) {
		while (!q.empty()) {
			int u = q.front();
			n++;
			for (int v : adj[u]) {
				if (!visit[v]) {
					visit[v] = true;
					q.push(v);
				}
			}
			q.pop();
		}
	}
	else {
		while (!q.empty()) {
			int u = q.front();
			n++;
			for (int v : adj_rev[u]) {
				if (!visit[v]) {
					visit[v] = true;
					q.push(v);
				}
			}
			q.pop();
		}
	}

	return n;
}

int solution() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		int taller = count(i);
		int smaller = count(i, false);
		if (taller + smaller == N - 1) cnt++;
	}
	return cnt;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj_rev[b].push_back(a);
	}

	printf("%d", solution());

	return 0;
}