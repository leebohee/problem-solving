#include<iostream>
#include <climits>
#include <stack>
#include <utility>
#include <algorithm>

#define MAX_N 4
#define MAX_W 12
#define MAX_H 15

using namespace std;

int N, W, H;
int result;
int map[MAX_H][MAX_W];
int copy_map[MAX_H][MAX_W];
int shoot[MAX_W];

bool valid(int h, int w) {
	if (w < 0 || w >= W || h < 0 || h >= H) return false;
	else return true;
}

void shoot_at(int w) {
	const static int dr[4] = { -1, 1, 0, 0 };
	const static int dc[4] = { 0, 0, -1, 1 };
	stack< pair<int, int> > st;
	bool visit[MAX_H][MAX_W] = { false, };

	for (int i = 0; i < H; i++) {
		if (copy_map[i][w] > 0) {
			st.push({ i, w });
			visit[i][w] = true;
			break;
		}
	}

	while (!st.empty()) {
		pair<int, int> pos = st.top();
		st.pop();

		int power = copy_map[pos.first][pos.second];
		copy_map[pos.first][pos.second] = 0;
	
		for (int i = 1; i < power; i++) {
			for (int j = 0; j < 4; j++) {
				int next_r = pos.first + i * dr[j];
				int next_c = pos.second + i * dc[j];
				if (valid(next_r, next_c)) {
					if (copy_map[next_r][next_c] > 1) {
						if (!visit[next_r][next_c]) {
							visit[next_r][next_c] = true;
							st.push({ next_r, next_c });
						}
					}
					else if (copy_map[next_r][next_c] == 1) copy_map[next_r][next_c] = 0;
				}
			}
		}
	}

	// remove blanks
	for (int i = 0; i < W; i++) {
		int read = H - 1, write = H - 1;
		while (read >= 0) {
			if (copy_map[read][i] == 0) read--;
			else {
				copy_map[write][i] = copy_map[read][i];
				write--;
				read--;
			}
		}
		while (write >= 0) {
			copy_map[write][i] = 0;
			write--;
		}
	}
}

int play() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			copy_map[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		// shoot
		shoot_at(shoot[i]);
	}

	// count left bricks
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (copy_map[i][j] > 0) cnt++;
		}
	}
	return cnt;
}

void min_bricks(int n) {
	if (n == N) {
		result = min(result, play());
		return;
	}
	for (int i = 0; i < W; i++) {
		shoot[n] = i;
		min_bricks(n + 1);
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> W >> H;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}
		result = INT_MAX;
		min_bricks(0);
		cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;
}