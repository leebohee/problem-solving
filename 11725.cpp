#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int* FindParent(int n, vector <int>* adj){
	int* parent = new int [n];
	bool chk[n] = {false};
	queue <int> q;  // use BFS
	int root = 0;

	q.push(root);
	while(!q.empty()){
		int visit = q.front();
		q.pop();
		
		if(!chk[visit]){
			chk[visit] = true;
			int size = adj[visit].size();
			// push adjacent vertex which is not visit
			for(int i=0; i<size; i++){
				int next = adj[visit][i];
				if(!chk[next]){
					q.push(next);
					parent[next] = visit;
				}
			}
		}	
	}
	return parent;
}

int main(){
	int N;
	cin >> N;
	vector <int> adj[N];  // adjacency list
	
	int u, v;
	for(int i=1; i<N; i++){
		cin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	
	int* result = FindParent(N, adj);
	for(int i=1; i<N-1; i++){
		cout << result[i]+1 << '\n';  // 'endl' includes flush, so it is much later than '\n'
	}
	cout << result[N-1]+1;
	
	return 0;
}
