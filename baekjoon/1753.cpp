#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cstdio>
#include <utility>

#define MAX_WEIGHT 3000000

using namespace std;

class Graph{
public:
	void make_graph(int V_, int E_){
		V = V_;
		E = E_;
		adj = new unordered_map<int, int> [V]; // (vertex, weight)
		int u, v, w;
		for(int i=0; i<E; i++){
			scanf("%d %d %d", &u, &v, &w);
			if(adj[u-1].find(v-1) == adj[u-1].end()){
				adj[u-1].insert({v-1, w});
			}
			else{
				adj[u-1][v-1] = min(adj[u-1][v-1], w);
			}
		}
	}

	void dijkstra(int src, int dist[]){
		int cur;
		bool visit[V];
		priority_queue< pair<int, int>, vector<pair<int, int> >, greater< pair<int, int> > > q; // (dist, vertex)

		// initialize distance vector
		for(int i=0; i<V; i++){
			dist[i] = MAX_WEIGHT;
			visit[i] = false;
		}
		dist[src] = 0;

		q.emplace(dist[src], src);
		while(!q.empty()){
			// choose next vertex
			cur = q.top().second;
			q.pop();
			if(visit[cur]) continue;

			// update visited vector
			visit[cur] = true;

			// update distance vector
			for(auto edge: adj[cur]){
				if(dist[edge.first] > dist[cur] + edge.second){
					dist[edge.first] = dist[cur] + edge.second;
					q.emplace(dist[edge.first], edge.first);
				}
			}
		}
	}
	~Graph(){
		delete [] adj;
	}
private:
	int V, E;
	unordered_map<int, int>* adj;
};

int main(){
	int V, E, K;
	Graph g;

	scanf("%d %d %d", &V, &E, &K);

	g.make_graph(V, E);
	int dist[V];
	g.dijkstra(K-1, dist);
	for(int i=0; i<V; i++){
		if(dist[i] == MAX_WEIGHT) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}
