#include <iostream>
#include <set>

#define MAX_N 28
#define MAX_LEN (MAX_N / 4)

using namespace std;

int N, K;
char edge[4][MAX_LEN];
char str[MAX_N * 2];

int convert_to_decimal(char* hex, int n) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (hex[i] >= '0' && hex[i] <= '9') {
			ret = ret * 16 + (hex[i] - '0');
		}
		else { // 'A' ~ 'F'
			ret = ret * 16 + (hex[i] - 'A' + 10);
		}
	}
	return ret;
}

int password() {
	int n = N / 4, ret, idx;
	set<int> candidates;

	// rotate n times
	for (int i = 0; i < n; i++) {
		idx = 0;
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < N / 4; k++) {
				edge[j][k] = str[i+idx];
				idx++;
			}
		}
		// convert numbers on each edge
		for (int j = 0; j < 4; j++) {
			ret = convert_to_decimal(edge[j], n);
			if (candidates.find(ret) == candidates.end()) {
				candidates.insert(ret);
			}
		}
	}
	// K-th largest element in the set
	int size = candidates.size();
	set<int>::iterator itr = candidates.begin(); // auto itr = candidates.begin();
	for (int i = 0; i < size - K; i++) {
		itr++;
	}
	return *itr;
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) {
			cin >> str[i];
			str[i + N] = str[i];
		}
		cout << '#' << test_case << ' ' << password() << '\n';
	}

	return 0;
}
