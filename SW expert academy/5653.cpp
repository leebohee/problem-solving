#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <utility>

using namespace std;

int N, M, K;

struct cell {
	int lifespan;
	int create;
	bool dead;
	cell() {};
	cell(int x, int t) : lifespan(x), create(t), dead(false) {};
};

set< pair<int, int> > cells; // (row, col)
map< pair<int, int>, cell > alive_cells;

int num_alive_cells() {
	const int dr[4] = { -1, 1, 0, 0 };
	const int dc[4] = { 0, 0, -1, 1 };
	int cur_time = 0;

	while (cur_time < K) {
		map< pair<int, int>, cell > new_cells; // ((row, col), cell)
		set < pair<int, int> > to_delete;
		for (auto itr = alive_cells.begin(); itr != alive_cells.end(); itr++) {
			pair<int, int> pos = itr->first;
			cell cur_cell = (itr->second);

			// become activate -> spread
			if (cur_time == cur_cell.create + cur_cell.lifespan) {
				for (int i = 0; i < 4; i++) {
					int r = pos.first + dr[i];
					int c = pos.second + dc[i];
					pair<int, int> next = { r, c };
					// no cell exists in that position
					if (cells.find(next) == cells.end()) {
						auto it = new_cells.find(next);
						if (it == new_cells.end()) {
							new_cells.insert({ next, cell(cur_cell.lifespan, cur_time + 1) });
						}
						else if (it->second.lifespan < cur_cell.lifespan) {
							// insert: 중복된 키에 대한 value 업데이트 X
							//new_cells.insert({ {r, c}, cell(cur_cell.lifespan, cur_time + 1) });

							// []: 중복된 키에 대한 value 업데이트 O
							it->second = cell(cur_cell.lifespan, cur_time + 1);
						}
					}
				}
			}
			// become dead
			if (cur_time + 1 == cur_cell.create + 2 * cur_cell.lifespan) {
				to_delete.insert(pos);
			}
		}
		for (auto itr = new_cells.begin(); itr != new_cells.end(); itr++) {
			alive_cells.insert({ itr->first, itr->second });
			cells.insert(itr->first);
		}
		cur_time++;

		for (auto itr = to_delete.begin(); itr != to_delete.end(); itr++) {
			alive_cells.erase(*itr);
		}
	}
	return alive_cells.size();
}

int main() {
	int T, x;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d %d", &N, &M, &K);
		cells.clear();
		alive_cells.clear();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d ", &x);
				if (x > 0) {
					alive_cells.insert({ {i, j}, cell(x, 0) });
					cells.insert({i, j});
				}
			}
		}
		printf("#%d %d\n", test_case, num_alive_cells());
	}



	return 0;
}
