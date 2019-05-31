#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int diff(vector <int> &height, int dumps){
	int size = height.size();
	int min = 0, max = size - 1;
	
	sort(height.begin(), height.end());
	for(int i=0; i<dumps; i++){
		if(height[max] - height[min] <= 1){ // complete flattening
			break;
		}
		height[min]++;
		height[max]--;
		if(height[min] > height[min+1]){
			min++;
		}
		else{
			min = 0;
		}
		if(height[max] < height[max-1]){
			max--;
		}
		else{
			max = size - 1;
		}
	}
	
	return (height[max] - height[min]);
}

int main(){
	int dumps, h;
	vector <int> height;
	
	for(int i=0; i<10; i++){
		cin >> dumps;
		for(int j=0; j<100; j++){
			cin >> h;
			height.push_back(h);
		}
		cout << '#' << i+1 << ' ' << diff(height, dumps) << '\n';
		height.clear();
	}
	return 0;
}
