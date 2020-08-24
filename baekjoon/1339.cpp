#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define SIZE 26

using namespace std;

int digit_sum[SIZE];

int main() {
	int N;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int i = str.length() - 1, p = 1; i >= 0; i--, p *= 10) {
			digit_sum[str[i] - 'A'] += p;
		}
	}

	sort(digit_sum, digit_sum + SIZE);

	int result = 0;
	for (int i = SIZE - 1, d = 9; i >= 0; i--, d--) {
		if (digit_sum[i] == 0) break;
		result += (digit_sum[i] * d);
	}

	cout << result;
	return 0;
}