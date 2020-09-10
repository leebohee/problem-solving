#include <cstdio>
#include <deque>
#include <utility>
#include <algorithm>

#define MAX_N 5000000

using namespace std;

int main() {
	int N, L, x;
	deque<pair<int, int> > deq; // (value, index)
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &L);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);

		while (!deq.empty() && deq.front().second < max(0, i - L + 1)) {
			deq.pop_front();
		}


		while (!deq.empty() && deq.back().first > x) {
			deq.pop_back();
		}

		deq.emplace_back(x, i);
		printf("%d ", deq.front().first);

	}

	return 0;
}