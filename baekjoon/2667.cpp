#include <stack>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	bool exist;
	bool visit;
	node(){
		exist = false;
		visit = false;
	}
};

struct graph {
	node** adj;
	int n;
	graph(int _n){
		adj = new node* [_n];
		for(int i=0; i<_n; i++){
			adj[i] = new node [_n];
		}
		n = _n;
	} 	
};

vector <int> CountComplex(graph* g){
	stack < pair <int, int> > s;
	vector <int> result;
	int n = g->n, len;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(g->adj[i][j].exist && !g->adj[i][j].visit){
				// DFS
				s.push(make_pair(i, j));
				len = result.size();
				result.push_back(0);
				while(!s.empty()){
					int x = s.top().first;
					int y = s.top().second;
					s.pop();
					if(g->adj[x][y].visit){
						continue;
					}
					g->adj[x][y].visit = true;
					result[len]++;
					
					// next visit
					if(x>0 && g->adj[x-1][y].exist && !g->adj[x-1][y].visit){
						s.push(make_pair(x-1, y));
					}
					if(y>0 && g->adj[x][y-1].exist && !g->adj[x][y-1].visit){
						s.push(make_pair(x, y-1));
					}
					
					if(x<n-1 && g->adj[x+1][y].exist && !g->adj[x+1][y].visit){
						s.push(make_pair(x+1, y));
					}
					
					if(y<n-1 && g->adj[x][y+1].exist && !g->adj[x][y+1].visit){
						s.push(make_pair(x, y+1));
					}
				}
			}
		}
	}
	return result;
}

int main(){
	int N;
	string in;
	cin >> N;
	graph* g = new graph(N);
	cin.ignore();
	for(int i=0; i<N; i++){
		getline(cin, in);
		for(int j=0; j<N; j++){
			if(in.at(j) == '1'){
				g->adj[i][j].exist = true;
			}
		}
	}
	
	vector <int> result = CountComplex(g);
	int size = result.size();
	sort(result.begin(), result.end());
	cout << size << endl;
	for(int i=0; i<size-1; i++){
		cout << result[i] << endl;
	}
	cout << result[size-1];
	
	return 0;
}
