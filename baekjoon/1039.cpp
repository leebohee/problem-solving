#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

/*
1 <= N <= 1,000,000
1 <= K <= 10

M을 N의 자릿수라고 할 때, 1 <= M <= 6
따라서 두 자릿수를 교환하는 경우의 수는 6*5/2 = 15
교환을 K번 하므로 최악의 시간복잡도는 10^15 < 10^16 (=2s) 이므로
BFS로 모든 경우의 수를 확인해보아도 주어진 시간 내에 해결할 수 있다!
*/

string swap_char(string str, int i, int j){
	char tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
	return str;
}

int min_num(int N, int K) {
	if (N < 10) return -1;

	int result = -1;
	queue<string> q;

	q.push(to_string(N));

	while (K--) {
		int n = q.size();
		unordered_set<string> nums;
		for (int i = 0; i < n; i++) {
			string& num = q.front();
			int len = num.length();

			for (int j = 0; j < len; j++) {
				for (int k = j + 1; k < len; k++) {
					if (j == 0 && num[k] == '0') continue;

					string next = swap_char(num, j, k);
					if (nums.find(next) != nums.end()) continue;
					nums.insert(next);
					q.push(next);
				}
			}
			q.pop();
		}
	}
	while (!q.empty()) {
		string& num = q.front();
		result = max(result, stoi(num));
		q.pop();
	}

	return result;
}

int main() {
	int N, K;

	scanf("%d %d", &N, &K);
	printf("%d", min_num(N, K));

	return 0;
}