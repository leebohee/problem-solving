#include <iostream>
#include <unordered_set>
#include <deque>
#include <utility>
#include <vector>
#define MAX_SIZE 100

using namespace std;

int N;
unordered_set<int> apples;

enum Dir{RIGHT, DOWN, LEFT, UP};

class Snake{
public:
	Snake(): dir(RIGHT) {
		body.push_front(0);
		body_pos.insert(0);
	};
	void rotate(int d){
		if(d == RIGHT) dir = (dir + 1) % 4;
		else dir = (dir +  3) % 4;
	}
	bool move();

private:
	int dir;
	unordered_set<int> body_pos;
	deque<int> body;
};

bool Snake::move(){
	const static int dr[4] = {0, 1, 0, -1}; // RIGHT, DOWN, LEFT, UP
	const static int dc[4] = {1, 0, -1, 0};

	int next_r = body.front() / N + dr[dir];
	int next_c = body.front() % N + dc[dir];
	int next_pos = body.front() + dr[dir]*N + dc[dir];

	// check collision with body
	if(body_pos.find(next_pos) != body_pos.end()) return false;
	
	// check collision with wall
	if(next_r < 0 || next_r >= N || next_c < 0 || next_c >= N) return false;

	// move forward
	body.push_front(next_pos);
	body_pos.insert(next_pos);
	if(apples.find(next_pos) == apples.end()){ // apple doesn't exists
		int tail = body.back();
		body.pop_back();
		body_pos.erase(tail);
	}
	else{ 
		apples.erase(next_pos);
	}
	return true;
}

int main(){
	int K, L, x, r, c, t = 0, idx = 0;
	char ch;
	cin >> N >> K;
	for(int i=0; i<K; i++){
		cin >> r >> c;
		apples.insert((r-1)*N + (c-1));
	}
	cin >> L;
	vector < pair <int, int > > rotate_info; // (time, rotate direction)
	rotate_info.reserve(L);
	for(int i=0; i<L; i++){
		cin >> x >> ch;
		rotate_info.push_back(make_pair(x, (ch == 'L'? LEFT : RIGHT)));
	}

	Snake snake;
	while(snake.move()){
		t++;
		if(rotate_info[idx].first == t){
			snake.rotate(rotate_info[idx].second);
			idx++;
		}
	}
	cout << t+1;
	return 0;
}
