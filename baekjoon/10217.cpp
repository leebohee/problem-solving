#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>

#define MAX_TIME 100000 // 1000*100 (t*N)

using namespace std;
using my_tuple = tuple<int, int, int>; // (accumulated_time, accumulated_cost, vertex)

struct edge{
	int v;
	int cost;
	int time;
	edge(int v_, int cost_, int time_)
	: v(v_), cost(cost_), time(time_) {};
};


int min_time(int N, int E, const vector<edge> adj[], int budget){
	int cur, total_time, total_cost = 0, ret;
	priority_queue<my_tuple, vector<my_tuple>, greater<my_tuple> > pq; 
	// min_time[i][j]: 노드 i까지 j원으로 도착하는 최소 시간
	int min_time[N+1][budget+1]; 

	for(int i=0; i<budget; i++) min_time[1][i] = 0;
	for(int i=2; i<N+1; i++){
		for(int j=0; j<budget+1; j++){
			min_time[i][j] = MAX_TIME;
		}
	}
	
	pq.emplace(0, 0, 1);
	while(!pq.empty()){
		tie(total_time, total_cost, cur) = pq.top();
		pq.pop();

		if(cur == N) return total_time;

		// update distance vector
		for(auto e: adj[cur]){
			int c = total_cost + e.cost;
			int next = e.v;
			if(c <= budget){
				if(min_time[next][c] > min_time[cur][total_cost] + e.time){
					min_time[next][c] = min_time[cur][total_cost] + e.time;
					pq.emplace(min_time[next][c], c, next);
				}
			}
		}
	}

	ret = MAX_TIME;
	for(int i=0; i<budget; i++){
		if(ret > min_time[N][i]) ret = min_time[N][i];
	}
	return ret;
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
		if(ret < 0 || ret == MAX_TIME) cout << "Poor KCM\n";
		else cout << ret << '\n';
	}

	return 0;
}
