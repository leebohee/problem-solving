#include <iostream>

using namespace std;

int main(){
	int N, sum = 0;
	string nums;
	cin >> N >> nums;
	for(int i=0; i<N; i++){
		sum += (nums.at(i)-'0');
	}
	cout << sum;
	return 0;
}
