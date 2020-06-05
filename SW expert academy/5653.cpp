#include <iostream>
#include <cstdio>
#include <map>
#include <set>

#define MAX_SIZE 651 // 300+50+300
#define OFFSET 300

//#pragma warning(disable : 4996)

using namespace std;

int N, M, K;
int container[MAX_SIZE][MAX_SIZE] = { 0, };
int alive_time[MAX_SIZE][MAX_SIZE] = { 0, };

int valid(int r, int c) {
	if (r < 0 || r >= MAX_SIZE || c < 0 || c >= MAX_SIZE) return false;
	else return true;
}

int num_alive_cells() {
	const int dr[4] = { -1, 1, 0, 0 };
	const int dc[4] = { 0, 0, -1, 1 };
	int cur_time = 0;

	while (cur_time < K) {
		map< pair<int, int>, int > new_cells; // ((row, col), lifespan)

		for (int i = OFFSET - cur_time; i <= OFFSET + N + cur_time; i++) {
			for (int j = OFFSET - cur_time; j <= OFFSET + M + cur_time; j++) {
				if (container[i][j] == -1) continue;
				if (container[i][j] > 0) {
					if (container[i][j] == alive_time[i][j]) { // become activate
						for (int k = 0; k < 4; k++) {
							int r = i + dr[k];
							int c = j + dc[k];
							if (!valid(r, c)) continue;
							if (container[r][c] == 0) {
								if (new_cells.find({ r, c }) == new_cells.end()) {
									new_cells.insert({ {r, c} , container[i][j] });
								}
								else if (new_cells[{r, c}] < container[i][j]) {
									new_cells[{r, c}] = container[i][j];
								}
							}
						}
					}
					if (2 * container[i][j] > alive_time[i][j]) {
						alive_time[i][j]++;
					}

					if (2 * container[i][j] == alive_time[i][j]) { // become dead
						container[i][j] = -1;
					}
				}
			}
		}
		for (auto itr = new_cells.begin(); itr != new_cells.end(); itr++) {
			pair<int, int> pos = itr->first;
			container[pos.first][pos.second] = itr->second;
			alive_time[pos.first][pos.second] = 0;
		}

		cur_time++;
	}
	int cnt = 0;
	for (int i = OFFSET - cur_time; i <= OFFSET + N + cur_time; i++) {
		for (int j = OFFSET - cur_time; j <= OFFSET + M + cur_time; j++) {
			if (container[i][j] > 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	int T, x;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d %d", &N, &M, &K);

		for (int i = 0; i < MAX_SIZE; i++) {
			for (int j = 0; j < MAX_SIZE; j++) {
				container[i][j] = alive_time[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &container[i + OFFSET][j + OFFSET]);
			}
		}
		printf("#%d %d\n", test_case, num_alive_cells());
	}



	return 0;
}
