#include <iostream>
#include <queue>

using namespace std;

int A[100001];

void H_index(int N){
	int H[100001] = {1, };
	// store citiations greater than current H-index
	priority_queue < int, vector<int>, greater<int> > pq; 

	if(A[0] > 1) pq.push(A[0]);
	for(int i=1; i<N; i++){
		if(H[i-1] < A[i]){
			pq.push(A[i]);
			if(pq.size() >= pq.top()){
				H[i] = pq.top();
				while(!pq.empty() && H[i] >= pq.top()) pq.pop();
				continue;
			}
			else if(pq.size() > H[i-1]){
				H[i] = H[i-1]+1;
				continue;
			}
		}
		H[i] = H[i-1];
	}

	// print H-indices
	for(int i=0; i<N; i++){
		cout << H[i] <<' ';
	}
	cout << '\n';
}

int main(){
	int T, N;
	cin >> T;
	for(int t=0; t<T; t++){
		cin >> N;
		for(int i=0; i<N; i++){
			cin >> A[i];
		}
		cout << "Case #" << t+1 << ": ";
		H_index(N);
	}
	return 0;
}