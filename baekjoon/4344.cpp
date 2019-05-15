#include <iostream>
#include <vector>

using namespace std;

float avgRatio(int n, vector <int> &score){
	float sum = 0.0, avg = 0.0;
	int cnt = 0;
	
	// average
	for(int i=0; i<n; i++){
		sum += (float)score[i];
	}
	avg = sum / n;
	
	// ratio of higher than average
	for(int i=0; i<n; i++){
		if(avg < (float)score[i]) cnt++;
	}
	return (float)cnt/(float)n;
}

int main(){
	int C, N, x;
	vector <int> score;
	
	// 소수점 셋째 자리까지 출력 
	cout << fixed;
	cout.precision(3);
	
	cin >> C;
	for(int i=0; i<C; i++){
		cin >> N;
		score.clear();
		for(int j=0; j<N; j++){
			cin >> x;
			score.push_back(x);
		}
		cout << avgRatio(N, score)*100 << "%\n";
	}
	
}
