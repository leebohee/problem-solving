#include <vector>
#include <iostream>

using namespace std;

int GCD(int a, int b){
	while(true){
		int r = a%b;
		if(r == 0){
			return b;
		}
		a = b;
		b = r;
	}
}

int LCM(int a, int b){
	return a*b/GCD(a, b);
}

int Cain(int M, int N, int x, int y){
	int limit = LCM(M, N) / N;
	int tmp;
	
	for(int a=0; a<=limit; a++){
		tmp = a*N+y-x;
		if(tmp%M == 0){
			int b = tmp/M;
			return (b*M+x);
		}
	}
	
	return -1;
}

int main(){
	int T, M, N, x, y;
	vector <int> result;
	
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> M >> N >> x >> y;
		result.push_back(Cain(M, N, x, y));	
	}
	
	for(int i=0; i<T-1; i++){
		cout << result[i] << endl;
	}
	cout << result[T-1];
	
	return 0;
}
