#include <vector>
#include <iostream>

using namespace std;

vector <int> MinSequence(int N, int L){
	vector <int> seq;
	
	while(L <= 100){
		if(L%2 == 0){ // L is even
			int x = (2*N+L) / (2*L);
			if(L/2 > x) break;
			if((2*N+L) % (2*L) == 0){
				int t = L / 2;
				for(int i=0; i<L; i++){
					seq.push_back(x-t+i);
				}
				return seq;
			}
			else{
				L++;
			}
		}
		else{ // L is odd
			int x = N / L;
			if(L/2 > x) break;
			if(N%L == 0){
				int t = L / 2;
				for(int i=0; i<L; i++){
					seq.push_back(x-t+i);
				}
				return seq;
			}
			else{
				L++;
			}
		}
	}
	seq.push_back(-1);
	return seq;
}

int main(){
	int N, L;
	
	cin >> N >> L;
	vector <int> result = MinSequence(N, L);
	
	int len = result.size();
	for(int i=0; i<len-1; i++){
		cout << result[i] << ' ';
	}
	cout << result[len-1];
	
	return 0;
}
