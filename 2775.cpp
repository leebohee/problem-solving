#include <vector>
#include <iostream>

using namespace std;

int ComputeNumWithRecursive(int floor, int room){
	int num = 0;
	static int memo1[14][14] = {0}; // memorize from 1st floor
		
	if(floor==0){
		return room;
	}
	
	if(memo1[floor-1][room-1] != 0){
		return memo1[floor-1][room-1];
	}
	else{
		for(int i=1; i<=room; i++){
			num += ComputeNumWithRecursive(floor-1, i);
		}
		memo1[floor-1][room-1] = num;
	}
	
	return num;
}

int ComputeNumWithoutRecursive(int floor, int room){
	static int memo2[15][14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0}; // memorize from 0th floor

	if(memo2[floor][room-1] != 0){
		return memo2[floor][room-1];
	}
	else{
		for(int i=1; i<floor; i++){
			for(int j=0; j<room; j++){
				if(memo2[i][j] != 0){
					continue;
				}
				for(int k=0; k<=j; k++){
					memo2[i][j] += memo2[i-1][k];
				}
			}
		}
		for(int i=0; i<room; i++){
			memo2[floor][room-1] += memo2[floor-1][i];
		}
	}
	
	return memo2[floor][room-1];
}

int main(){
	int T, floor, room;
	vector <int> result;
	
	cin >> T;
	
	for(int i=0; i<T; i++){
		cin >> floor >> room;
		result.push_back(ComputeNumWithRecursive(floor, room));
		// result.push_back(ComputeNumWithoutRecursive(floor, room));
	}
	for(int i=0; i<T-1; i++){
		cout << result[i] << endl;
	}
	cout << result[T-1];
	
	return 0;
}
