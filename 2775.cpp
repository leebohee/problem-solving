#include <vector>
#include <iostream>

using namespace std;

int ComputeNum(int floor, int room){
	int num = 0;
	static int memo[14][14] = {0};
		
	if(floor==0){
		return room;
	}
	
	if(memo[floor-1][room-1] != 0){
		return memo[floor-1][room-1];
	}
	else{
		for(int i=1; i<=room; i++){
			num += ComputeNum(floor-1, i);
		}
		memo[floor-1][room-1] = num;
	}
	
	return num;
}

int main(){
	int T, floor, room;
	vector <int> result;
	
	cin >> T;
	
	for(int i=0; i<T; i++){
		cin >> floor >> room;
		result.push_back(ComputeNum(floor, room));
	}
	for(int i=0; i<T-1; i++){
		cout << result[i] << endl;
	}
	cout << result[T-1];
	
	return 0;
}
