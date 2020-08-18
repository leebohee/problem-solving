#include <cstdio>
#include <vector>
#include <queue>

#define MAX_N 32000

using namespace std;

int N, M;
vector<int> adj[MAX_N+1];
int in_degree[MAX_N+1];

void topological_sort(){
	queue<int> q;
	for(int i=1; i<=N; i++){
		if(in_degree[i] == 0) q.push(i);
	}

	while(!q.empty()){
		int u = q.front();
		printf("%d ", u);

		for(int v: adj[u]){
			in_degree[v]--;
			if(in_degree[v] == 0) q.push(v);
		}
		q.pop();
	}
}


int main(){
	scanf("%d %d", &N, &M);

	for(int i=0; i<M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		in_degree[b]++;
	}

	topological_sort();
	return 0;
}