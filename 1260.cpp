#include <stack>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

bool AllVisited(bool* visited, int N){
	for(int i=0; i<N; i++){
		if(!visited[i]){
			return false;
		}
	}
	return true;
}

void DFS(bool** g, int N, int start){
	bool* visited = new bool [N];
	memset(visited, false, N);
	stack <int> s;
	int v;
	
	s.push(start);
	while(!s.empty()){
		v = s.top();
		s.pop();
		if(!visited[v]){
			visited[v] = true;
			cout << v+1 << ' ';
			if(AllVisited(visited, N)){
				break;
			}
			for(int i=N-1; i>=0; i--){
				if(g[v][i] && !visited[i]){
					s.push(i);
				}
			}	
		}
	}
	delete [] visited;
}

void BFS(bool** g, int N, int start){
	bool* visited = new bool [N];
	memset(visited, false, N);
	queue <int> q;
	int v;

	q.push(start);
	while(!q.empty()){
		v = q.front();
		q.pop();
		if(!visited[v]){
			visited[v] = true;
			cout << v+1 << ' ';
			if(AllVisited(visited, N)){
				break;
			}
			for(int i=0; i<N; i++){
				if(g[v][i] && !visited[i]){
					q.push(i);
				}
			}	
		}
	}
	delete [] visited;
}

int main(){
	int N, M, sv;
	cin >> N >> M >> sv;
	
	bool** adj = new bool* [N];
	for(int i=0; i<N; i++){
		adj[i] = new bool [N];
		memset(adj[i], false, sizeof(bool)*N);
	}
	
	int v1, v2;
	for(int i=0; i<M; i++){
		cin >> v1 >> v2;
		adj[v1-1][v2-1] = true;
		adj[v2-1][v1-1] = true;
	}

	DFS(adj, N, sv-1);
	cout << endl;
	BFS(adj, N, sv-1);
	
	for(int i=0; i<N; i++){
		delete [] adj[i];
	}
	delete [] adj; 
}

