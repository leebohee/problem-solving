#include <iostream>
#include <unordered_map>


#define MAX_N 100

using namespace std;

struct Pos{
	int row;
	int col;
	Pos(int r, int c): row(r), col(c) {};
	bool operator==(const Pos& p){
		if(this->row == p.row && this->col == p.col) return true;
		else return false;
	}
};

enum {UP, DOWN, LEFT, RIGHT};

class PinBall{
public:
	void init(){
		worm.clear();
		cin >> N;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin >> board[i][j];
				if(board[i][j] > 5){
					auto it = worm.find(board[i][j]);
					if(it == worm.end()){
						worm.insert(make_pair(board[i][j], make_pair(Pos(i, j), Pos(-1, -1))));
					}
					else{
						(it->second).second = Pos(i, j);
					}
				}
			}
		}
	}

	int max_score(){
		int ret = -1;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				for(int d=0; d<4; d++){
					ret = max(ret, play(Pos(i, j), d));
				}
			}
		}
		return ret;
	}
private:
	int N;
	int board[MAX_N][MAX_N];
	unordered_map<int, pair<Pos, Pos> > worm;

	bool check_collision(int r, int c, int d){
		if(r < 0 || r >= N || c < 0 || c >= N) return true;
		if(board[r][c] == 5) return true;

		if(board[r][c] == 1 && (d == RIGHT || d == UP)) return true;
		if(board[r][c] == 2 && (d == RIGHT || d == DOWN)) return true;
		if(board[r][c] == 3 && (d == LEFT || d == DOWN)) return true;
		if(board[r][c] == 4 && (d == LEFT || d == UP)) return true;
		
		return false;
	}

	bool valid(int r, int c){
		if(r < 0 || r >= N || c < 0 || c >= N) return false;
		else return true;
	}

	int play(Pos start, int dir){
		const static int dr[4] = {-1, 1, 0, 0}; // 상, 하, 좌, 우
		const static int dc[4] = {0, 0, -1, 1};
		
		int r = start.row, c = start.col, d = dir;
		int score = 0;

		// start from empty cell
		if(board[r][c] != 0) return -1;

		do{
			switch(board[r][c]){
				case 1:
					if(d == DOWN || d == LEFT){
						d = (d + 2) % 4;
						score++;
					}
					break;
				case 2:
					if(d == UP || d == LEFT){
						d = (d + 3) % 4;
						score++;
					}
					break;
				case 3:
					if(d == UP || d == RIGHT){
						d = (d + 2) % 4;
						score++;
					}
					break;
				case 4:
					if(d == DOWN || d == RIGHT){
						d = (d + 1) % 4;
						score++;
					}
					break;
			}
			int next_r = r + dr[d];
			int next_c = c + dc[d];

			if(check_collision(next_r, next_c, d)){
				score++;
				d = d + (d % 2 ? -1 : 1);
				next_r = r;
				next_c = c;
			}
			if(board[next_r][next_c] > 5){ // worm hole
				auto it = worm.find(board[next_r][next_c]);
				if(it->second.first == Pos(next_r, next_c)){
					r = it->second.second.row;
					c = it->second.second.col;
				}
				else{
					r = it->second.first.row;
					c = it->second.first.col;
				}
			}
			else{
				r = next_r;
				c = next_c;
			}
			
		} while(board[r][c] >= 0 && !(r == start.row && c == start.col));
		return score;
	}
};

int main(){
	PinBall game;

	int T;
	cin >> T;
	for(int test_case=1; test_case<=T; test_case++){
		game.init();
		cout << '#' << test_case << ' ' << game.max_score() << '\n';
	}
	return 0;
}
