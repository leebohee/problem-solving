#include <vector>
#include <iostream>

using namespace std;

int views(vector <int> &height){
	int size = height.size();
	int views = 0, tmp;
	
	for(int i=2; i<size-2; i++){
		tmp = height[i] -height[i-2];
		tmp = min(tmp, height[i] - height[i-1]);
		tmp = min(tmp, height[i] - height[i+1]);
		tmp = min(tmp, height[i] - height[i+2]);
		views += max(tmp, 0);
	}
	return views;
}

int main(){
	int size, h;
	vector <int> height;
	
	for(int i=0; i<10; i++){
		cin >> size;
		for(int j=0; j<size; j++){
			cin >> h;
			height.push_back(h);
		}
		cout << '#' << i+1 << ' ' << views(height) << '\n';
		height.clear();
	}
	return 0;
}
