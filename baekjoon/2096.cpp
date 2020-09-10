#include <cstdio>

#define SIZE 100000
#define MAX 987654

using namespace std;

int N;
int arr[SIZE][3];
int memo[SIZE][3];

int min(int a, int b, int c = MAX) {
	if (a > b) {
		if (b > c) return c;
		else return b;
	}
	else { // b >= a
		if (a > c) return c;
		else return a;
	}
}

int max(int a, int b, int c = -1) {
	if (a < b) {
		if (b < c) return c;
		else return b;
	}
	else { // b <= a
		if (a < c) return c;
		else return a;
	}
}

void compute_score(bool is_max = true) {
	if (is_max) {
		for (int i = N - 2; i >= 0; i--) {
			memo[i][0] = arr[i][0] + max(memo[i + 1][0], memo[i + 1][1]);
			memo[i][1] = arr[i][1] + max(memo[i + 1][0], memo[i + 1][1], memo[i + 1][2]);
			memo[i][2] = arr[i][2] + max(memo[i + 1][1], memo[i + 1][2]);
		}
	}
	else {
		for (int i = 0; i < N - 1; i++)
		{
			memo[i][0] = memo[i][1] = memo[i][2] = MAX;
		}
		for (int i = N - 2; i >= 0; i--) {
			memo[i][0] = arr[i][0] + min(memo[i + 1][0], memo[i + 1][1]);
			memo[i][1] = arr[i][1] + min(memo[i + 1][0], memo[i + 1][1], memo[i + 1][2]);
			memo[i][2] = arr[i][2] + min(memo[i + 1][1], memo[i + 1][2]);
		}
	}

	
}

int main() {
	freopen("input.txt", "r", stdin);
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
	// initialize
	for (int i = 0; i < 3; i++) {
		memo[N - 1][i] =  arr[N - 1][i];
	}

	compute_score();
	int result1 = max(memo[0][0], memo[0][1], memo[0][2]);
	compute_score(false);
	int result2 = min(memo[0][0], memo[0][1], memo[0][2]);
	
	printf("%d %d", result1, result2);
	return 0;
}