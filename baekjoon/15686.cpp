#include <iostream>
#include <climits>
#include <vector>

#define MAX_N 50
#define MAX_M 13

using namespace std;

struct Pos{
	int r;
	int c;
	Pos(int r_, int c_): r(r_), c(c_) {};
	void print(){
		cout << "r = " << r << ", c = " << c << endl;
	}
};

int N, M;
int city[MAX_N][MAX_N];
bool visited[MAX_M];

int selected = 0;
int min_dist = INT_MAX;

vector<Pos> chicken;
vector<Pos> house;
int n_chicken = 0;
int n_house = 0;

int distance(Pos& p1, Pos& p2){
	return abs(p1.r-p2.r) + abs(p1.c-p2.c);
}

int chicken_dist(){
	int total_dist = 0;
	for(int i=0; i<n_house; i++){
		int dist = INT_MAX;
		for(int j=0; j<n_chicken; j++){
			if(visited[j]){
				dist = min(dist, distance(house[i], chicken[j]));
			}
		}
		total_dist += dist;
	}

	return total_dist;
}

void dfs(int index){
	visited[index] = true;
	selected++;

	if(selected == M){
		min_dist = min(min_dist, chicken_dist());
	}
	else{
		for(int i=index+1; i<n_chicken; i++){
			dfs(i);
		}
	}

	visited[index] = false;
	selected--;
}

int main(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> city[i][j];
			if(city[i][j] == 1){
				n_house++;
				house.emplace_back(i, j);
			}
			else if(city[i][j] == 2){
				n_chicken++;
				chicken.emplace_back(i, j);
			}
		}
	}
	for(int i=0; i<n_chicken; i++) dfs(i);
	cout << min_dist;
    return 0;
}