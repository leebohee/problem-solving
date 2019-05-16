#include <iostream>

using namespace std;

int cycleLength(int n){
	int cnt = 0, prev_num = n, cur_num = -1;
	int digit1, digit0; // number = digit1*10 + digit0
	
	while(cur_num != n){
		// generate new number
		digit0 = prev_num % 10;
		digit1 = (prev_num / 10) % 10;
		cur_num = digit0 * 10 + ((digit1 + digit0) % 10);
		cnt++;
		prev_num = cur_num;
	}
	return cnt;
}

int main(){
	int n;
	cin >> n;
	
	cout << cycleLength(n);
	return 0;
}
