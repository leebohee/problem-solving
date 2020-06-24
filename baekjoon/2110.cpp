#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_adj_dist(int N, int C, vector<int>& x){
	sort(x.begin(), x.end());
	int left = 1, right = x[N-1]-x[0];
	int ret = -1;
	while(left <= right){
		int mid = left + (right - left) / 2;
		int install = 0, cnt = 1;
		for(int i=1; i<N; i++){
			if(mid <= x[i] - x[install]){
				cnt++;
				install = i;
			}
		}
		if(cnt >= C){ // too close
			ret = mid;
			left = mid + 1;
		}
		else{ // too far
			right = mid - 1;
		}
	}
	return ret;
}

int main(){
	int N, C, tmp;
	vector<int> x;
	
	cin >> N >> C;
	x.reserve(N);
	for(int i=0; i<N; i++){
		cin >> tmp;
		x.push_back(tmp);
	}
	cout << max_adj_dist(N, C, x);
	return 0;
}
