#include <iostream>

#define MAX_SIZE 500

using namespace std;

int N, M;
int map[MAX_SIZE][MAX_SIZE];

int max_sum(){
	int sum = 0, result = 0;
	// case 1
	for(int i=0; i<N; i++){
		for(int j=0; j<M-3; j++){
			sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3];
			result = max(result, sum);
		}
	}
	for(int i=0; i<N-3; i++){
		for(int j=0; j<M; j++){
			sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
			result = max(result, sum);
		}
	}

	// case 2
	for(int i=0; i<N-1; i++){
		for(int j=0; j<M-1; j++){
			sum = map[i][j] + map[i][j+1] + map[i+1][j] + map[i+1][j+1];
			result = max(result, sum);
		}
	}	

	for(int i=0; i<N-1; i++){
		for(int j=0; j<M-2; j++){
			// case 3-1
			sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2];
			result = max(result, sum);
			// case 4-2
			sum = sum - map[i][j] + map[i][j+1];
			result = max(result, sum);
			// case 3-4
			sum = sum - map[i][j+1] + map[i][j+2];
			result = max(result, sum);
				
		}
	}	
	for(int i=0; i<N-1; i++){
		for(int j=0; j<M-2; j++){
			// case 3-2
			sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j];
			result = max(result, sum);
			// case 4-1
			sum = sum - map[i+1][j] + map[i+1][j+1];
			result = max(result, sum);
			// case 3-3
			sum = sum - map[i+1][j+1] + map[i+1][j+2];
			result = max(result, sum);
		}
	}	
	for(int i=0; i<N-2; i++){
		for(int j=0; j<M-1; j++){
			// case 3-5
			sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i][j+1];
			result = max(result, sum);
			// case 4-3
			sum = sum - map[i][j+1] + map[i+1][j+1];
			result = max(result, sum);
			// case 3-7
			sum = sum - map[i+1][j+1] + map[i+2][j+1];
			result = max(result, sum);
		}
	}	


	for(int i=0; i<N-2; i++){
		for(int j=1; j<M; j++){
			// case 3-6
			sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i][j-1];
			result = max(result, sum);
			// case 4-4
			sum = sum - map[i][j-1] + map[i+1][j-1];
			result = max(result, sum);
			// case 3-8
			sum = sum - map[i+1][j-1] + map[i+2][j-1];
			result = max(result, sum);
		}
	}	


	for(int i=1; i<N-1; i++){
		for(int j=0; j<M-1; j++){
			// case 5-1
			sum = map[i][j] + map[i-1][j] + map[i][j+1] + map[i+1][j+1];
			result = max(result, sum);
			// case 5-2
			sum = sum - map[i-1][j] - map[i+1][j+1] + map[i-1][j+1] + map[i+1][j];
			result = max(result, sum);
		}
	}	

	
	for(int i=0; i<N-1; i++){
		for(int j=1; j<M-1; j++){
			// case 5-3
			sum = map[i][j] + map[i+1][j] + map[i][j+1] + map[i+1][j-1];
			result = max(result, sum);
			// case 5-4
			sum = sum - map[i][j+1] - map[i+1][j-1] + map[i][j-1] + map[i+1][j+1];
			result = max(result, sum);
		}
	}		

	return result;
}

int main(){
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
		}
	}
	cout << max_sum() << endl;
	return 0;
}
