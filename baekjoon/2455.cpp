#include <algorithm>
#include <iostream>

using namespace std;

int Max(int* info){
	int num[4] = {0};
	
	num[0] = info[1];
	for(int i=1; i<4; i++){
		num[i] = num[i-1] - info[2*i] + info[2*i+1]; 
	}
	
	return *max_element(num, num+4);
}

int main(){
	int info[8];
	
	for(int i=0; i<4; i++){
		cin >> info[2*i] >> info[2*i+1];	
	}
	
	cout << Max(info);
	
	return 0;
}
