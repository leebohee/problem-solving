#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool binary_search(const vector<int>& v, int target){
	static const int n = v.size();
	int left = 0, right = n-1, mid;
	while(left <= right){
		mid = left + (right - left) / 2;
		if(v[mid] == target) return true;
		else if(v[mid] > target) right = mid - 1;
		else left = mid + 1;
	}
	return false;
}

int main(){
	int N, M, x, ret;

	scanf("%d", &N);

	vector<int> v;
	v.reserve(N);
	for(int i=0; i<N; i++){
		scanf("%d", &x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	unordered_map<int, bool> memo;
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		scanf("%d", &x);
		auto itr = memo.find(x);
		if(itr == memo.end()){
			ret = binary_search(v, x);
			memo.insert({x, ret});
		}
		else{
			ret = itr->second;
		}
		printf("%d\n", ret);
	}

	return 0;
}
