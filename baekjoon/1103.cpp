#include <iostream>
#include <cstdio>
#include <algorithm>

#define SIZE 50

using namespace std;

char board[SIZE][SIZE];
bool visit[SIZE][SIZE];
int memo[SIZE][SIZE];
int N, M;
int result = 0;

struct Pos {
	int r;
	int c;
	Pos(int r_ = 0, int c_ = 0) : r(r_), c(c_) {};
};

bool valid(Pos& cur) {
	if (cur.r < 0 || cur.r >= N || cur.c < 0 || cur.c >= M) return false;
	else return true;
}

int dfs(Pos& cur, int move) {
	const static int dr[4] = { -1, 1, 0, 0 };
	const static int dc[4] = { 0, 0, -1, 1 };
	if (!valid(cur)) return 0;
	if (board[cur.r][cur.c] == 'H') return 0;

	if (memo[cur.r][cur.c] <= 0) {
		visit[cur.r][cur.c] = true;
		result = max(result, move);
		for (int i = 0; i < 4; i++) {
			int next_r = cur.r + (board[cur.r][cur.c] - '0') * dr[i];
			int next_c = cur.c + (board[cur.r][cur.c] - '0') * dc[i];
			Pos next = Pos(next_r, next_c);
			if (valid(next) && visit[next_r][next_c]) {
				printf("-1");
				exit(0);
			}
			memo[cur.r][cur.c] = max(memo[cur.r][cur.c], dfs(next, move + 1) + 1);
		}
		visit[cur.r][cur.c] = false;
	}
	
	return memo[cur.r][cur.c];
}

int main() {
	char ch;

	scanf("%d %d ", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%c", &board[i][j]);
		}
		scanf("%c", &ch);
	}
	Pos start;
	dfs(start, 0);
	printf("%d\n", memo[0][0]);
	return 0;
}