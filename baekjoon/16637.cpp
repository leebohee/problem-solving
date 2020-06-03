#include <iostream>
#include <climits>

#define MAX_N 19

using namespace std;

int N, max_res = INT_MIN;;
char expr[MAX_N];

int compute(int* expression, int n) {
	int result = expression[0];
	for (int i = 1; i < n; i += 2) {
		switch (expression[i]) {
		case '+':
			result += expression[i + 1];
			break;
		case '-':
			result -= expression[i + 1];
			break;
		case '*':
			result *= expression[i + 1];
			break;
		}
	}
	return result;
}

void max_result(int idx, int* new_expr, int n) {
	if (idx >= N - 1) {
		if (idx == N - 1) new_expr[n++] = expr[idx] - '0';
		max_res = max(max_res, compute(new_expr, n));
		return;
	}

	for (int i = idx; i < N - 2; n += 2, i += 2) {
		// apply bracket
		switch (expr[i + 1]) {
		case '+':
			new_expr[n] = (expr[i] - '0') + (expr[i + 2] - '0');
			break;
		case '-':
			new_expr[n] = (expr[i] - '0') - (expr[i + 2] - '0');
			break;
		case '*':
			new_expr[n] = (expr[i] - '0') * (expr[i + 2] - '0');
			break;
		}
		new_expr[n + 1] = expr[i + 3];
		max_result(i + 4, new_expr, n + 2);

		// doesn't apply bracket
		new_expr[n] = expr[i] - '0';
		new_expr[n + 1] = expr[i + 1];
		max_result(i + 2, new_expr, n + 2);
	}
}

int main() {
	int new_expr[MAX_N];

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> expr[i];
	}

	max_result(0, new_expr, 0);
	cout << max_res;
	return 0;
}