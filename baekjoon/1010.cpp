#include <iostream>
#include <vector>
#include <cstring>

#define MAX_SIZE 30

using namespace std;

int CaseBridges(int N, int M, int** memo){
	if(N == 0 || N == M){
		return 1;
	}
	if(memo[N][M] == 0){
		memo[N][M] = CaseBridges(N-1, M-1, memo)+CaseBridges(N, M-1, memo);
	}
	return memo[N][M];
}

int main(){
	int T, N, M;
	vector <int> result;
	int** memo = new int* [MAX_SIZE];
	for(int j=0; j<MAX_SIZE; j++){
		memo[j] = new int [MAX_SIZE];
		memset(memo[j], 0, sizeof(int)*MAX_SIZE);
	}
	
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> N >> M;
		result.push_back(CaseBridges(N, M, memo));
	}
	
	for(int i=0; i<T-1; i++){
		cout << result[i] << endl;
	}
	cout << result[T-1];
	
	for(int j=0; j<MAX_SIZE; j++){
		delete [] memo[j];
	}
	delete [] memo;
	return 0;
}
