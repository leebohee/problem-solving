#include <iostream>
#include <queue>
#include <tuple>
#include <climits>

#define MAX_N 20
#define MAX_DIST INT_MAX

using namespace std;

int N;
int sea[MAX_N][MAX_N];

class BabyShark{
public:
	BabyShark(int r_, int c_): size(2), r(r_), c(c_) {};

	int max_time(){
		int t = 0, eat = 0;
		int row, col, dist, min_dist, next_r, next_c;
		int fish_r, fish_c;
		const int dr[4] = {-1, 0, 0, 1}; // 상, 좌, 우, 하
		const int dc[4] = {0, -1, 1, 0};

		while(true){
			bool visit[N][N];
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					visit[i][j] = false;
				}
			}

			min_dist = MAX_DIST;
			fish_r = N;
			fish_c = N;
			// find fish to eat using BFS
			queue< tuple<int, int, int> > q;
			q.push({r, c, 0});
			while(!q.empty()){
				tie(row, col, dist) = q.front();
				q.pop(); 

				if(visit[row][col]) continue;
				visit[row][col] = true;

				if(dist > min_dist) break;

				// update fish to eat
				if(sea[row][col] > 0 && sea[row][col] < size){
					if(fish_r > row || (fish_r == row && fish_c > col)){
						min_dist = dist;
						fish_r = row;
						fish_c = col;
					}
				}
				
				for(int i=0; i<4; i++){
					next_r = row + dr[i];
					next_c = col + dc[i];
					if(valid(next_r, next_c)){
						q.push({next_r, next_c, dist+1});
					}
				}
			}
			// no fish to eat
			if(min_dist == MAX_DIST) break;

			// move to the fish and eat it
			r = fish_r;
			c = fish_c;
			t += min_dist;
			sea[r][c] = 0;
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
		}
	}
	BabyShark baby(r, c);
	cout << baby.max_time();
}
