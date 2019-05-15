#include <vector>
#include <iostream>

using namespace std;

void print(vector <int> &nums){
	int n = nums.size();
	for(int i=0; i<n; i++){
		cout << nums[i] << '\n';
	}
}

void bubbleSort(vector <int> &nums){
	int n = nums.size();
	
	for(int i=n-1; i>=0; i--){
		for(int j=0; j<i; j++){
			if(nums[j] > nums[j+1]){
				swap(nums[j], nums[j+1]);
			}
		}
	}
} 

void selectionSort(vector <int> &nums){
	int n = nums.size(), min, idx;
	
	for(int i=0; i<n; i++){
		min = nums[i];
		idx = i;
		for(int j=i+1; j<n; j++){ // find minimum element
			if(nums[j] < min){
				min = nums[j];
				idx = j;
			}
		}
		swap(nums[i], nums[idx]);
	}
} 

void insertionSort(vector <int> &nums){
	int n = nums.size(), tmp, j;
	
	for(int i=1; i<n; i++){
		tmp = nums[i];
		for(j=i-1; j>=0; j--){
			if(nums[j] > tmp){
				nums[j+1] = nums[j];
			}
			else{
				break;
			}
		}
		nums[j+1] = tmp;
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
//	bubbleSort(nums);
//	selectionSort(nums);
	insertionSort(nums);
	print(nums);
	return 0;
}
