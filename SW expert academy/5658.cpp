#include <iostream>
#include <set>

#define MAX_N 28
#define MAX_LEN (MAX_N / 4)

using namespace std;

int N, K;
char edge[4][MAX_LEN];

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
	int n = N / 4, ret;
	set<int> candidates;

	// rotate n times
	for (int i = 0; i < n; i++) {
		//cout << "===== " << i << "th rotate ======\n";
		// convert numbers on each edge
		for (int j = 0; j < 4; j++) {
			ret = convert_to_decimal(edge[j], n);
			if (candidates.find(ret) == candidates.end()) {
				candidates.insert(ret);
			}
			for (int k = 0; k < n; k++) {
				//cout << edge[j][k];
			}
			//cout << '(' << ret << ')' << '\n';
		}
		// rotate
		int store;
		for (int j = 3; j >= 0; j--) {
			int temp = edge[j][n - 1];
			for (int k = n - 1; k > 0; k--) {
				edge[j][k] = edge[j][k - 1];
			}
			if (j < 3) edge[j + 1][0] = temp;
			else store = temp;
		}
		edge[0][0] = store;
	}
	int size = candidates.size();
	int idx = 0;
	//cout << size - K << endl;
	for (auto itr = candidates.begin(); itr != candidates.end(); itr++) {
		cout << *itr << endl;
		if (idx < size - K) idx++;
		else {
			ret = *itr;
			break;
		}
	}
	return ret;
	//auto itr = candidates.begin();
	
	//return *(candidates.begin() + (size - 1 - K));
	//return candidates[size - 1 - K]; // k-th largest element
}

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> K;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < N / 4; j++) {
				cin >> edge[i][j];
			}
		}
		cout << '#' << test_case << ' ' << password() << '\n';
	}
	

	return 0;
}