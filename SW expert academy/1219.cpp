#include <iostream>

#define MAX_CNT 100

using namespace std;

int cnt;
int graph[MAX_CNT][2];

void init_graph(){
	for(int i = 0; i < MAX_CNT; i++){
		graph[i][0] = graph[i][1] = -1;
	}
}

int reach(){ // DFS
	bool visit[MAX_CNT] = {false, };
	int stack[MAX_CNT*MAX_CNT];
	int idx = 0, u, v;
	
	stack[idx++] = 0; // push start-point
	while(idx > 0){
		// pop
		v = stack[--idx];
		if(visit[v]) continue;
		visit[v] = true;
		// check if it is end-point
		if(v == 99) return 1;
		// push adjacent vertex
		for(int i = 0 ; i < 2; i++){
			u = graph[v][i];
			if(u >= 0 && !visit[u]) stack[idx++] = u;
		}
	}
	return 0;
}

int main(){
	int src, dest;
	for(int test_case = 1; test_case <= 10; test_case++){
		init_graph();
		cin >> cnt;
		cin >> cnt;
		for(int i = 0; i < cnt; i++){
			cin >> src >> dest;
			if(graph[src][0] < 0){
				graph[src][0] = dest;
			}
			else{
				graph[src][1] = dest;
			}
		}
		cout << '#' << test_case << ' ' << reach() << '\n';
	}
	return 0;
}
