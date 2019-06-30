#include <iostream>
#include <climits>
#include <cstring>

#define SIZE 100

using namespace std;

int maxSum(int* arr[]){
	int max = INT_MIN, tmp;
	
	// max among rows
	for(int i=0; i<SIZE; i++){
		tmp = 0;
		for(int j=0; j<SIZE; j++){
			tmp += arr[i][j];
		}
		if(max < tmp){
			max = tmp;
		}
	}
	
	// max among rows, columns
	for(int i=0; i<SIZE; i++){
		tmp = 0;
		for(int j=0; j<SIZE; j++){
			tmp += arr[j][i];
		}
		if(max < tmp){
			max = tmp;
		}
	}
	
	// max among rows, columns, cross
	for(int i=0; i<1; i++){
		tmp = 0;
		for(int j=0; j<SIZE; j++){
			tmp += (i? arr[j][j] : arr[j][SIZE-j]);
		}
		if(max < tmp){
			max = tmp;
		}
	}
	return max;
}

int main(){
	int** arr;
	int x;
	
	arr = new int* [SIZE];
	for(int i=0; i<SIZE; i++){
		arr[i] = new int [SIZE];
		memset(arr[i], 0, sizeof(int)*SIZE);
	}
	for(int i=0; i<10; i++){
		cin >> x;	
		for(int j=0; j<SIZE; j++){
			for(int k=0; k<SIZE; k++){
				cin >> arr[j][k];
			}
		}
		cout << '#' << i+1 << ' ' << maxSum(arr) << '\n';
	}	
	for(int i=0; i<SIZE; i++){
		delete [] arr[i];
	}
	delete [] arr;
	return 0;
}
