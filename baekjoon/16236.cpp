#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <tuple>
#include <climits>

#define MAX_N 20
#define MAX_DIST INT_MAX

using namespace std;

int N;
int sea[MAX_N][MAX_N];

struct fish{
	int size;
	int r;
	int c;
	bool exist;
	fish(int size_, int r_, int c_): size(size_), r(r_), c(c_), exist(true) {};
};

vector<fish> fishes;
unordered_set<int> fishes1;

class BabyShark{
public:
	BabyShark(int r_, int c_): size(2), r(r_), c(c_) {};

	int max_time(){
		int t = 0, n = fishes.size(), min_dist, dist, fidx, eat = 0;
		bool find;

		while(true){
			// choose fish to eat
			min_dist = MAX_DIST;
			fidx = -1;
			for(int i=0; i<n; i++){
				if(fishes[i].exist && fishes[i].size < size){
					dist = can_reach(r, c, fishes[i].r, fishes[i].c);
					if(dist > 0 && min_dist > dist){
						min_dist = dist;
						fidx = i;
					}
				}
				
			}
			
			if(fidx < 0) break;

			// move to the fish and eat it
			r = fishes[fidx].r;
			c = fishes[fidx].c;
			t += min_dist;
			fishes[fidx].exist = false;
			eat++;
			if(eat == size){
				size++;
				eat = 0;
			}
		}
		return t;
	}

private:
	int size;
	int r;
	int c;

	bool valid(int r, int c){
		if(r < 0 || r >= N || c < 0 || c >= N) return false;
		else if(sea[r][c] > size) return false;
		return true;
	}

	int can_reach(int src_r, int src_c, int dest_r, int dest_c){
		int row, col, dist, next_r, next_c;
		const int dr[4] = {-1, 0, 0, 1}; // 상, 좌, 우, 하
		const int dc[4] = {0, -1, 1, 0};

		queue< tuple<int, int, int> > q;
		q.push({r, c, 0});

		bool visit[N][N];
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				visit[i][j] = false;
			}
		}
		
		while(!q.empty()){
			tie(row, col, dist) = q.front();
			q.pop(); 

			if(visit[row][col]) continue;
			visit[row][col] = true;

			if(row == dest_r && col == dest_c) return dist;
			
			for(int i=0; i<4; i++){
				next_r = row + dr[i];
				next_c = col + dc[i];
				if(valid(next_r, next_c)){
					q.push({next_r, next_c, dist+1});
				}
			}
		}
		return -1;
	}
};


int main(){
	int r = 0, c = 0;
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> sea[i][j];
			if(sea[i][j] == 9){
				r = i;
				c = j;
				sea[i][j] = 0;
			}
			else if(sea[i][j] > 0){
				fishes.emplace_back(sea[i][j], i, j);
				fishes1.insert(i*N + j);
			}
		}
	}
	BabyShark baby(r, c);
	cout << baby.max_time();
}