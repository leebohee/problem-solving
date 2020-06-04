#include<iostream>
#include <queue>
#include <set>
#include <map>
#include <cstdio>

#define MAX_SIZE 50
#define OFFSET 301

using namespace std;

struct cell {
	int row;
	int col;
	int create;
	int lifespan;
	int check;
	bool activate;
	cell(int r, int c, int t, int x, int check_) 
		: row(r), col(c), create(t), lifespan(x), check(check_), activate(false) {};
};

int N, M, K;
int container[MAX_SIZE][MAX_SIZE];

int num_cells() {
	const int dr[4] = { -1, 1, 0, 0 };
	const int dc[4] = { 0, 0, -1, 1 };
	int cur_time = 0, r, c, pos;
	queue<cell> q;
	set<int> dead_cells;
	set<int> cells; // activated + inactivated cells
	map<int, int> new_cells; // (pos, lifespan) to set as largest lifespan

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (container[i][j] > 0) {
				pos = (i + OFFSET) * 1000 + (j + OFFSET);
				if (new_cells.find(pos) == new_cells.end()) {
					new_cells.insert({ pos, container[i][j] });
				}
				else if(new_cells[pos] < container[i][j]){ // update 
					new_cells.insert({ pos, container[i][j] });
				}
			}
		}
	}

	for (auto itr = new_cells.begin(); itr != new_cells.end(); itr++) {
		pos = itr->first;
		r = pos / 1000 - OFFSET;
		c = pos % 1000 - OFFSET;
		q.push({ r, c, 0, itr->second, 0 });
	}

	while (cur_time < K) {
		
		new_cells.clear();
		cells.clear();

		int idx = 0, size = q.size();
		while (idx < size) {
			cell cur_cell = q.front();
			q.pop();

			pos = (cur_cell.row + OFFSET) * 1000 + (cur_cell.col + OFFSET);
			cells.insert(pos);
			
			q.push(cur_cell);
			idx++;
		}

		while (true) {
			cell cur_cell = q.front();
			if (cur_cell.check != cur_time) break;
			
			q.pop();
			pos = (cur_cell.row + OFFSET) * 1000 + (cur_cell.col + OFFSET);
			if (cur_time == cur_cell.create + 2 * cur_cell.lifespan) { // dead
				dead_cells.insert(pos);
				continue;
			}
			else {
				cur_cell.check++;
				q.push(cur_cell);
				cur_cell.check--;
			}

			// become activate
			if (cur_time == cur_cell.create + cur_cell.lifespan) { 
				cur_cell.activate = true;
				for (int i = 0; i < 4; i++) {
					r = cur_cell.row + dr[i];
					c = cur_cell.col + dc[i];
					pos = (r + OFFSET) * 1000 + (c + OFFSET);
					if (dead_cells.find(pos) == dead_cells.end() && cells.find(pos) == cells.end()) {
						if (new_cells.find(pos) == new_cells.end()) {
							new_cells.insert({ pos, cur_cell.lifespan });
						}
						else if (new_cells[pos] < cur_cell.lifespan) { // update 
							new_cells.insert({ pos, cur_cell.lifespan });
						}
					}
				}
			}		
		}

		for (auto itr = new_cells.begin(); itr != new_cells.end(); itr++) {
			pos = itr->first;
			r = pos / 1000 - OFFSET;
			c = pos % 1000 - OFFSET;
			q.push({ r, c, cur_time+1, itr->second, cur_time+1 });
		}
		cur_time++;
	}


	int idx = 0, size = q.size();
	while (idx < size) {
		cell cur_cell = q.front();
		q.pop();

		if (cur_time == cur_cell.create + 2 * cur_cell.lifespan) { // dead
			continue;
		}

		q.push(cur_cell);
		idx++;
	}
	return q.size();
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &container[i][j]);
			}
		}
		printf("#%d %d\n", test_case, num_cells());
	}
	return 0;
}