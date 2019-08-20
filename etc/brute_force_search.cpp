#include <iostream>

#define N 3

using namespace std;

int map[N][N] = {0, };
bool visit[N][N] = {false, };

bool valid(int r, int c){
	if(r < 0 || r >= N || c < 0 || c >= N) return false;
	else return true;
}

void brute_force(){
	// delta array (up, down, left, right)
	int dr[] = {-1, 1, 0, 0}; 
	int dc[] = {0, 0, -1, 1};
	int next_r, next_c;
	
	for(int r=0; r<N; r++){
		for(int c=0; c<N; c++){
			cout << "visit (" << r << ", " << c << ")\n";
			visit[r][c] = true;
			for(int k=0; k<3; k++){
				next_r = r + dr[k];
				next_c = c + dc[k];
				if(valid(next_r, next_c) && !visit[next_r][next_c]){
					cout << "visit (" << next_r << ", " << next_c << ")\n";
					visit[next_r][next_c] = true;
				}
			}
		}
	}	
}

int main(){
	brute_force();
	return 0;
}
