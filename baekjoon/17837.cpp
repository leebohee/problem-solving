#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX_N 12

using namespace std;

enum direction {RIGHT, LEFT, UP, DOWN};
enum color {WHITE, RED, BLUE};

int N, K;
int board[MAX_N][MAX_N];

struct horse{
	int r;
	int c;
	int pos; // position in 1-dim
	int dir;
	int id;

	horse(int r_, int c_, int d_, int id_): r(r_), c(c_), dir(d_), id(id_) {
		pos = r_ * N + c_;
	}
	void update(int r_, int c_, int d_=-1){
		r = r_;
		c = c_;
		pos = r * N + c;
		if(d_ >= 0) dir = d_;
	}
};

vector<horse> horses;
unordered_map< int, vector<int> > states;

const int dr[4] = {0, 0, -1, 1};
const int dc[4] = {1, -1, 0, 0};

bool valid(int r, int c){
	if(r < 0 || r >= N || c < 0 || c >= N) return false;
	else return true;
}

void white(horse& h, int next_r, int next_c){
	int idx, next_pos, n;
	vector<int> stack;

	auto itr = states.find(h.pos);
	vector<int>& hlist = itr->second;
	n = hlist.size();

	for(int i=0; i<n; i++){
		if(hlist[i] == h.id){
			for(int j=i; j<n; j++){
				stack.push_back(hlist[j]);
			}
			idx = i;
			break;
		}
	}
	for(int i=n-1; i>=idx; i--){
		hlist.pop_back();
	}
					
	next_pos = next_r * N + next_c;
	itr = states.find(next_pos);
	if(itr == states.end()){
		states.insert(make_pair(next_pos, stack));
		for(auto hid: stack){
			horses[hid].update(next_r, next_c);
		}
	}
	else{
		for(auto hid: stack){
			(itr->second).push_back(hid);
			horses[hid].update(next_r, next_c);
		}
	}
}

void red(horse& h, int next_r, int next_c){
	int idx, next_pos, n;
	vector<int> stack;
	
	auto itr = states.find(h.pos);
	vector<int>& hlist = itr->second;
	n = hlist.size();

	for(int j=0; j<n; j++){
		if(hlist[j] == h.id){
			idx = j;
			break;
		}
	}
	for(int j=n-1; j>=idx; j--){
		stack.push_back(hlist[j]);
		hlist.pop_back();
	}
	
	next_pos = next_r * N + next_c;
	itr = states.find(next_pos);
	if(itr == states.end()){
		states.insert(make_pair(next_pos, stack));
		for(auto hid: stack){
			horses[hid].update(next_r, next_c);
		}
	}
	else{
		for(auto hid: stack){
			(itr->second).push_back(hid);
			horses[hid].update(next_r, next_c);
		}
	}
}

int total_turn(){
	int turns = 0, next_r, next_c, next_pos;

	for(int i=0; i<K; i++){
		vector<int> v;
		v.push_back(horses[i].id);
		states.insert(make_pair(horses[i].pos, v));
	}

	while(turns < 1000){
		turns++;
		// move horse
		for(int i=0; i<K; i++){
			horse& h = horses[i];
			next_r = h.r + dr[h.dir];
			next_c = h.c + dc[h.dir];

			if(!valid(next_r, next_c) || board[next_r][next_c] == BLUE){
				// revert direction
				if(h.dir == RIGHT || h.dir == UP) h.update(h.r, h.c, h.dir+1);
				else h.update(h.r, h.c, h.dir-1);

				next_r = h.r + dr[h.dir];
				next_c = h.c + dc[h.dir];
				
				// move horse
				if(valid(next_r, next_c) && board[next_r][next_c] != BLUE){
					if(board[next_r][next_c] == WHITE) white(h, next_r, next_c);
					else red(h, next_r, next_c);
				}
			}
			else if(board[next_r][next_c] == WHITE){
				white(h, next_r, next_c);
			}
			else{ // RED
				red(h, next_r, next_c);
			}
			next_pos = next_r * N + next_c;
			auto itr = states.find(next_pos);
			if(itr != states.end() && itr->second.size() >= 4) return turns;
		}
	}
	return -1;
}

int main(){
	int r, c, d;
	cin >> N >> K;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> board[i][j];
		}
	}

	// reserve K
	horses.reserve(K);
	for(int i=0; i<K; i++){
		cin >> r >> c >> d;
		horses.emplace_back(r-1, c-1, d-1, i);
	}

	cout << total_turn();

	return 0;
}
