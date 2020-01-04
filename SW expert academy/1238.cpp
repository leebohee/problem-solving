#include<iostream>

#define QSIZE 100

using namespace std;

int N;
int start;
int adj[101][101]; // adj[i][0]: # of adjacent vertex (=n), adj[i][1]~adj[i][n]: adjacent vertex
bool exist[101][101];

int queue[QSIZE];
int head, tail;

void init(){
	for(int i=0; i<101; i++){
		for(int j=0; j<101; j++){
			exist[i][j] = false;
			adj[i][j] = 0;
		}
	}
	head = tail = 0;
}

int size(){
	return (tail-head);
}

bool empty(){
	if(head == tail) return true;
	else return false;
}

bool full(){
	if(tail == QSIZE) return true;
	else return false;
}

void insert(int v){
	if(full()){
		cout << "Queue is full -> cannot insert\n";
		return;
	}
	queue[tail++] = v;
}

void pop(int *v){
	if(empty()){
		cout << "Queue is empty --> cannot pop\n";
		return;
	}
	*v = queue[head++];
}

int unreachable(){
	bool visit[101] = {false, };
	int v, result, n, u;

	insert(start);
	while(!empty()){
		n = size();
		result = -1;
		for(int i=0; i<n; i++){
			pop(&v);
			for(int j=1; j<=adj[v][0]; j++){
				u = adj[v][j];
				if(exist[v][u] && !visit[u]){
					insert(u);
					visit[u] = true;
				}
			}
			if(result < v) result = v;
		}
	}
	return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T, len, u, v;

	for(test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> len >> start;
		N = len / 2;
		init();
		for(int i=0; i<N; i++){
			cin >> u >> v;
			if(exist[u][v]) continue;
			exist[u][0] = true;
			exist[u][v] = true;
			adj[u][++adj[u][0]] = v;
		}
		cout << '#' << test_case << ' ' << unreachable() << '\n';
	}
	return 0;
}