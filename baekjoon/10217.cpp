#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <unordered_map>

#define MAX_DIST 10000000 // 1000*10000 (E*t)

using namespace std;

struct edge{
	int v;
	int cost;
	int d;
	edge(int v_, int cost_, int d_)
	: v(v_), cost(cost_), d(d_) {};
};

int min_time(int N, int E, const vector<edge> adj[], int budget){
	int cur, d, total_cost = 0;
	int visit[N+1];
	int dist[N+1];
	// priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq; // (accumulated_cost, vertex)
	priority_queue< tuple<int, int, int>, vector< tuple<int, int, int> >, greater< tuple <int, int, int> > > pq; // (accumulated_dist, accumulated_cost, vertex)
	//unordered_map <int, int> to_be_visited; // (vertex, accumulated_dist)

	for(int i=0; i<N+1; i++){
		visit[i] = false;
		dist[i] = MAX_DIST;	
	}
	dist[1] = 0;

	pq.emplace(0, 0, 1);
	//to_be_visited.insert({1, 0});
	while(!pq.empty()){
		auto tup = pq.top();
		d = get<0>(tup);
		total_cost = get<1>(tup);
		cur = get<2>(tup);
		pq.pop();

		//if(visit[cur]) continue;
		visit[cur] = true;
		//to_be_visited.erase(cur);
		//cout << "visit " << cur << '\n';
		//cout << "visit " << cur << " cost " << d << endl;
		//if(total_cost > budget) continue; //return -1;
		if(cur == N) return d;

		// update distance vector
		for(auto e: adj[cur]){
			if(dist[e.v] > dist[cur] + e.d){
			//auto itr = to_be_visited.find(e.v);
			//if(itr == to_be_visited.end() || itr->second > dist[cur] + e.d){
				if(total_cost + e.cost <= budget){
					dist[e.v] = dist[cur] + e.d;
					pq.emplace(dist[e.v], total_cost + e.cost, e.v);
					//to_be_visited[e.v] = dist[e.v];
					//to_be_visited.insert({e.v, dist[e.v]});
				}
				//cout << "push " << e.v << " : accumulated_dist = " << dist[e.v] << ", accumulated_cost =" << total_cost+e.cost << '\n';
			}
		}
		dist[cur] = MAX_DIST;
	}

	//if(total_cost > budget) return -1;

	return dist[N];
}

int main(){
	int T, N, M, K, u, v, c, d, ret;

	cin >> T;
	for(int i=0; i<T; i++){
		cin >> N >> M >> K;
		vector<edge> adj[N+1];
		for(int	j=0; j<K; j++){
			cin >> u >> v >> c >> d;
			adj[u].emplace_back(v, c, d); // construct
			// construct->copy(=add to vector)->destruct
			// adj[u].push_back(edge(u, v, c, d)); 
			// adj[u].emplace_back(edge(u, v, c, d));
		}	
		ret = min_time(N, K, adj, M);
		if(ret < 0 || ret == MAX_DIST) cout << "Poor KCM\n";
		else cout << ret << '\n';
	}

	return 0;
}
