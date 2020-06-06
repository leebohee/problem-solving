#include <iostream>
#include <algorithm>

#define MAX_N 10
#define MAX_H 30

using namespace std;

int N, M, H;
bool map[MAX_H][MAX_N] = { false, };
int to_add;

bool verify() {
	for (int i = 0; i < N; i++) {
		int c = i;
		for (int j = 0; j < H; j++) {
			if (c < N - 1 && map[j][c]) c++;
			else if (c > 0 && map[j][c - 1]) c--;
		}
		if (c != i) return false;
	}
	return true;
}

void min_add(int n, int r) {
	if (n > 3) return;

	if (verify()) to_add = min(to_add, n);

	for (int i = r; i < H; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j]) continue;
			if (j > 0 && map[i][j - 1]) continue;
			if (j == N - 2 && map[i][j + 1]) continue;
			map[i][j] = true;
			min_add(n + 1, i);
			map[i][j] = false;
		}
	}
}

int main() {
	int a, b;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> H;
	int arr[N];
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a - 1][b - 1] = true;
	}
	to_add = 4;
	min_add(0, 0);
	cout << (to_add > 3 ? -1 : to_add);
	return 0;
}