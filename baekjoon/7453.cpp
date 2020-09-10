#include <cstdio>
#include <algorithm>

#define MAX_N 4000
using namespace std;

int AB[MAX_N * MAX_N], CD[MAX_N * MAX_N];

int main() {
	int n;
	int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];

	freopen("input.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	}

	for (int a = 0; a < n; a++) {
		for (int b = 0; b < n; b++) {
			AB[a * n + b] = A[a] + B[b];
			CD[a * n + b] = -1 * (C[a] + D[b]);
		}
	}

	int nn = n * n;
	sort(AB, AB + nn);
	long long cnt = 0;
	for (int i = 0; i < nn; i++) {
		int* lb = lower_bound(AB, AB + nn, CD[i]);
		int* ub = upper_bound(AB, AB + nn, CD[i]);
		cnt += (ub - lb);
	}
	printf("%lld", cnt);
	return 0;
}