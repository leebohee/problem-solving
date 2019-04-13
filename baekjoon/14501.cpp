#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(const vector <int> &a, const vector <int> &b){
	if(a[1] == b[1]){
		return a[2] < b[2];
	}
	else{
		return a[1] < b[1];
	}
}

int ComputeMaxPay(vector < vector <int> > &works, int* (&prev), int n, int* (&memo)){
	if(n == -1){
		return 0;
	}
	if(memo[n] == 0){
		memo[n] = max(ComputeMaxPay(works, prev, prev[n], memo)+works[n][2], ComputeMaxPay(works, prev, n-1, memo));
	}
	return memo[n];
}

int MaxPay(int N, int T[], int P[]){
	vector < vector <int> > works; // (start date, end date, pay)
	vector <int> v;
	int cnt = 0;
	
	for(int i=0; i<N; i++){
		if(i+T[i] > N){
			continue;
		}
		v.push_back(i+1);
		v.push_back(i+T[i]);
		v.push_back(P[i]);
		works.push_back(v);
		v.clear();
		cnt++;
	}
	sort(works.begin(), works.end(), cmp);
	
	int* prev = new int [cnt];
	memset(prev, -1, sizeof(int)*cnt);
	for(int i=cnt-1; i>=0; i--){
		for(int j=i; j>=0; j--){
			if(works[j][1] < works[i][0]){
				prev[i] = j;
				break;
			}
		}
	}

	int* memo = new int [cnt];
	memset(memo, 0, sizeof(int)*cnt);
	int result = ComputeMaxPay(works, prev, cnt-1, memo);
	
	delete [] prev;
	return result;
}

int main(){
	int N, t, p;
	cin >> N;
	
	int* T = new int [N];
	int* P = new int [N];
	for(int i=0; i<N; i++){
		cin >> t >> p;
		T[i] = t;
		P[i] = p;
	}
	
	cout << MaxPay(N, T, P);
	
	delete [] T;
	delete [] P;
	return 0;
}
