#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int mostFrequent(vector <int>& nums){
	int size = nums.size();
	int freq = -1, start = 0, end = 1, num = 1;
	
	sort(nums.begin(), nums.end());
	while(end < size){
		if(nums[start] != nums[end]){
			if(num <= end - start){
				num = end - start;
				freq = nums[start];
			}
			start = end;
		}
		end++;
	}
	return freq;
}

int main(){
	int T, x;
	vector <int> nums;
	
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> x;
		for(int j=0; j<1000; j++){
			cin >> x;
			nums.push_back(x);
		}
		cout << '#' << i+1 << ' ' << mostFrequent(nums) << '\n';
		nums.clear();
	}
	return 0;
}
