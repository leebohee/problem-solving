#include <iostream>
#include <vector>
#include <climits>

#define MAX_N 12

using namespace std;

struct Pos{
	int row;
	int col;
	Pos(int r, int c): row(r), col(c) {};
};

vector<Pos> cores;
int board[MAX_N][MAX_N];
int N;
int len, max_n;

void init(){
	cores.clear();
	max_n = 0;
	len = INT_MAX;
}

bool valid(int r, int c){
	if(r < 0 || r >= N || c < 0 || c >= N) return false;
	else return true;
}

int wire_length(){
	int wire = 0;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(board[i][j] == 2) wire++;
		}
	}

	return wire;
}

void connect(int idx, int n){
	if(cores.size() - idx + n < max_n) return;

	if(idx == cores.size()){
		if(max_n == n) len = min(len, wire_length());
		else{
			len = wire_length();
			max_n = n;
		}
		return;
	}
	const Pos& core = cores[idx];
	if(core.row == 0 || core.row == N-1 || core.col == 0 || core.col == N-1){
		connect(idx+1, n+1);
		return;
	}

	const int dr[4] = {-1, 1, 0, 0};
	const int dc[4] = {0, 0, -1, 1};

	connect(idx+1, n);

	for(int i=0; i<4; i++){
		int l = 1;
		bool possible = true;
		while(true){
			int next_r = core.row + l*dr[i];
			int next_c = core.col + l*dc[i];

			if(!valid(next_r, next_c)) break;
			if(board[next_r][next_c] != 0){
				possible = false;
				break;
			}
			l++;
		}
		if(!possible) continue;
		for(int j=1; j<l; j++){
			int next_r = core.row + j*dr[i];
			int next_c = core.col + j*dc[i];
			board[next_r][next_c] = 2;
		}
		connect(idx+1, n+1);
		for(int j=1; j<l; j++){
			int next_r = core.row + j*dr[i];
			int next_c = core.col + j*dc[i];
			board[next_r][next_c] = 0;
		}
	}
}

int main(int argc, char** argv){
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
		cin >> N;
		init();
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin >> board[i][j];
				if(board[i][j]) cores.emplace_back(i, j);
			}
		}
		connect(0, 0);
		cout << '#' << test_case << ' ' << len << '\n';

	}
	return 0;
}
