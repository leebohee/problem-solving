#include <iostream>
#include <stack>

#define MAX_N 16

using namespace std;

enum {RIGHT, CROSS, DOWN};

struct pos{
	int r;
	int c;
	pos(int r_, int c_): r(r_), c(c_) {};
};

struct pipe{
	pos start;
	pos end;
	int dir;
	pipe(pos start_, pos end_, int dir_): start(start_), end(end_), dir(dir_) {};
};

int N;
int map[MAX_N][MAX_N];

bool valid(const pipe& p){
	// check range
	if(p.start.r < 0 || p.start.r >= N || p.start.c < 0 || p.start.c >= N) return false;
	if(p.end.r < 0 || p.end.r >= N || p.end.c < 0 || p.end.c >= N) return false;
	// check wall
	if(map[p.start.r][p.start.c] || map[p.end.r][p.end.c]) return false;
	if(p.dir == CROSS){
		if(map[p.start.r][p.end.c] || map[p.end.r][p.start.c]) return false;
	}
	return true;
}

int num_routes(){
	int routes = 0;
	const int dr[3] = {0, 1, 1};
	const int dc[3] = {1, 1, 0};
	stack<pipe> st;

	st.push({pos(0, 0), pos(0, 1), RIGHT});
	while(!st.empty()){
		pipe cur = st.top();
		st.pop();
		
		// check destination
		if(cur.end.r == N-1 && cur.end.c == N-1){
			routes++;
			continue;
		}

		switch(cur.dir){
			case RIGHT:
			for(int i=0; i<2; i++){
				pipe next = {cur.end, pos(cur.end.r+dr[i], cur.end.c+dc[i]), i};
				if(valid(next)){
					st.push(next);
				}
			}
			break;
			case CROSS:
			for(int i=0; i<3; i++){
				pipe next = {cur.end, pos(cur.end.r+dr[i], cur.end.c+dc[i]), i};
				if(valid(next)){
					st.push(next);
				}
			}
			break;
			case DOWN:
			for(int i=1; i<3; i++){
				pipe next = {cur.end, pos(cur.end.r+dr[i], cur.end.c+dc[i]), i};
				if(valid(next)){
					st.push(next);
				}
			}
			break;
		}

 	}


	return routes;
}

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> map[i][j];
		}
	}
	cout << num_routes();
	return 0;
}