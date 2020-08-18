#include <iostream>

using namespace std;

int main(){
	int N, K, ret = 1;
	cin >> N >> K;
	if(K > N / 2) K = N - K;
	for (int i = 0; i < K; i++)
	{
		ret *= (N-i);
	}
	for (int i = 1; i <= K; i++)
	{
		ret /= i;
	}
	cout << ret;
	return 0;
}