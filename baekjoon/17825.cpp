#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <tuple>

#define NUM_TURNS 10

using namespace std;

struct board {
	int route[21] = { -1, }; // on_route = 0
	int route10[4] = { 10, 13, 16, 19 }; // on_route = 1
	int route20[3] = { 20, 22, 24 }; // on_route = 2
	int route30[4] = { 30, 28, 27, 26 }; // on_route = 3
	int route25[3] = { 25, 30, 35 }; // on_route = 4
	board() {
		for (int i = 1; i <= 20; i++) {
			route[i] = i * 2;
		}
	}
} game_board;

struct horse {
	int on_route;
	int pos;
	int id;
	bool finish;

	horse(int id_) : on_route(0), pos(0), id(id_), finish(false){};
	int move_forward(int move_cnt) {
		const static int route_len[] = { 20, 3, 2, 3, 2 };
		passby.push({ on_route, pos });
		if (on_route == 0) {
			if (pos == 20) {
				finish = true;
			}
			else if (pos % 5 == 0) {
				on_route = pos / 5;
				pos = 0;
			}
		}
		pos += move_cnt;
		if (pos > route_len[on_route]) {
			if (on_route == 0) {
				finish = true;
			}
			else if (on_route < 4) {
				pos -= (route_len[on_route] + 1);
				on_route = 4;
			}

			if (on_route == 4) {
				if (pos == route_len[on_route] + 1) {
					on_route = 0;
					pos = 20;
				}
				else if (pos > route_len[on_route]) finish = true;
			}
		}
		if (finish) {
			return 0;
		}
		switch (on_route) {
		case 0:
			return game_board.route[pos];
		case 1:
			return game_board.route10[pos];
		case 2:
			return game_board.route20[pos];
		case 3:
			return game_board.route30[pos];
		default:
			return game_board.route25[pos];
		}
	}
	void move_backward() {
		finish = false;
		tie(on_route, pos) = passby.top();
		passby.pop();
	}


private:
	stack < pair<int, int> > passby; // (prev on_route, prev pos)
};

int turns[NUM_TURNS];
vector<horse> horses;
int max_score = INT_MIN;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

void start_game(int turn, int score, int hid) {
	int get;
	bool collision;

	if (turn == NUM_TURNS) {
		max_score = max(max_score, score);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		if (horses[i].finish) continue;
		
		get = horses[i].move_forward(turns[turn]);

		// check collision with other horse
		collision = false;
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			if (!horses[j].finish && horses[i].on_route == horses[j].on_route && horses[i].pos == horses[j].pos) {
				collision = true;
				break;
			}
		}

		// next turn if collision doesn't occur
		if (!collision) start_game(turn + 1, score + get, i); 
		
		horses[i].move_backward();
	}
}

int main() {
	for (int i = 0; i < NUM_TURNS; i++) {
		cin >> turns[i];
	}

	// initialize horses
	for (int i = 0; i < 4; i++) {
		horses.emplace_back(i);
	}

	start_game(0, 0, 0);
	cout << max_score;
	return 0;
}