#include <queue>
#include <vector>
#include <iostream>

using namespace std;

void print(vector <int> &nums){
	int n = nums.size();
	for(int i=0; i<n; i++){
		cout << nums[i] << '\n';
	}
}
void merge(vector <int> &nums, int s, int mid, int e){
	vector <int> tmp;
	int left = s, right = mid+1;
	
	// merge two sub array into temporary buffer
	while(left <= mid && right <= e){
		if(nums[left] < nums[right]){
			tmp.push_back(nums[left]);
			left++;
		}
		else{
			tmp.push_back(nums[right]);
			right++;
		}
	}
	while(left<=mid){
		tmp.push_back(nums[left]);
		left++;
	}
	while(right<=e){
		tmp.push_back(nums[right]);
		right++;
	}
	
	// copy temporary buffer into original array
	int n = tmp.size();
	for(int i=0; i<n; i++, s++){
		nums[s] = tmp[i];
	}
}
void mergeSort(vector <int> &nums, int s, int e){
	int n = e - s + 1;
	
	if(n <= 1) return;
	mergeSort(nums, s, (s+e)/2);
	mergeSort(nums, (s+e)/2+1, e);
	merge(nums, s, (s+e)/2, e);
} 

void heapSort(vector <int> &nums){
	priority_queue <int, vector <int>, greater <int> > pq;
	int n = nums.size();
	
	for(int i=0; i<n; i++){
		pq.push(nums[i]);
	}
	for(int i=0; i<n; i++){
		nums[i] = pq.top();
		pq.pop();
	}
}

int main(){
	int n, x;
	vector <int> nums;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		nums.push_back(x);
	}
	//mergeSort(nums, 0, n-1);
	heapSort(nums);
	print(nums);
	return 0;
}
