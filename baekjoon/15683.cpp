#include <iostream>
#include <vector>

#define MAX_SIZE 8
#define WALL 6

using namespace std;

struct Cctv{
	int r;
	int c;
	int type;
	Cctv(int r_, int c_, int t_): r(r_), c(c_), type(t_) {};
};

enum {UP, RIGHT, DOWN, LEFT};

int N, M, K, result = MAX_SIZE*MAX_SIZE;
int map[MAX_SIZE][MAX_SIZE];
int copy_map[MAX_SIZE][MAX_SIZE];
vector<Cctv> cctv;
int dir[MAX_SIZE];

void monitor(int r, int c, int d){
	switch(d){
		case UP:
			for(int i=r-1; i>=0; i--){
				if(copy_map[i][c] == WALL){
					break;
				}
				copy_map[i][c] = -1;
			}
			break;
		case RIGHT:
			for(int i=c+1; i<M; i++){
				if(copy_map[r][i] == WALL){
					break;
				}
				copy_map[r][i] = -1;
			}
			break;
		case DOWN:
			for(int i=r+1; i<N; i++){
				if(copy_map[i][c] == WALL){
					break;
				}
				copy_map[i][c] = -1;
			}
			break;
		case LEFT:
			for(int i=c-1; i>=0; i--){
				if(copy_map[r][i] == WALL){
					break;
				}
				copy_map[r][i] = -1;
			}
	}
}

void compute_blind(){
	int row, col, blind = 0;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			copy_map[i][j] = map[i][j];
		}
	}

	for(int i=0; i<K; i++){
		row = cctv[i].r;
		col = cctv[i].c;
		switch(cctv[i].type){
			case 1:
				monitor(row, col, (dir[i]+1)%4);
				break;
			case 2:
				monitor(row, col, (dir[i]+1)%4);
				monitor(row, col, (dir[i]+3)%4);
				break;
			case 3:
				monitor(row, col, (dir[i]+1)%4);
				monitor(row, col, dir[i]);
				break;
			case 4:
				monitor(row, col, dir[i]);
				monitor(row, col, (dir[i]+1)%4);
				monitor(row, col, (dir[i]+3)%4);
				break;
			case 5:
				monitor(row, col, UP);
				monitor(row, col, RIGHT);
				monitor(row, col, DOWN);
				monitor(row, col, LEFT);
		}
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(copy_map[i][j] == 0) blind++;
		}
	}

	result = min(result, blind);
}

void min_blind(int n){
	if(n == K){
		compute_blind();
		return;
	}

	switch(cctv[n].type){
		case 1:
		case 3:
		case 4:
			for(int i=0; i<4; i++){
				dir[n] = i;
				min_blind(n+1);
			}
			break;
		case 2:
			for(int i=0; i<2; i++){
				dir[n] = i;
				min_blind(n+1);
			}
			break;
		case 5:
			dir[n] = 0;
			min_blind(n+1);
	}


}

int main(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
			if(map[i][j] >= 1 && map[i][j] <= 5){
				cctv.push_back(Cctv(i, j, map[i][j]));
			}
		}
	}
	K = cctv.size();
	min_blind(0);
	cout << result;
}
