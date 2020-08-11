#include <iostream>
#include <climits>
#include <unordered_map>

using namespace std;

unordered_map<int, int> memo;

long long pow(int A, int B, int C){
	if(B == 1) return A % C;
	auto it = memo.find(B);
	if(it == memo.end()){
		long long ret = pow(A, B/2, C);
		ret = (ret * ret) % C;
		if(B % 2 == 0) memo.emplace(B, ret);
		else memo.emplace(B, (ret * A) % C);
	}
	return memo[B];
}

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << pow(A, B, C);
	return 0;
}