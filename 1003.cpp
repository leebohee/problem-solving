#include <vector>
#include <utility>
#include <iostream>

using namespace std;

pair <int, int> operator+(const pair <int, int> &a, const pair <int, int> &b){
	return make_pair(a.first+b.first, a.second+b.second);
}

pair <int, int> CountCall(int n){
	static vector < pair <int, int> > mem = {make_pair(1, 0), make_pair(0, 1)};
	
	if(mem.size() > n){ // use memorization
		return mem[n];
	}
	
	if(n > 1){
		mem.push_back(CountCall(n-1) + CountCall(n-2));
		return mem[n];
	}
}

int main(){
	int T, N;
	vector <pair <int, int> > result;
	cin >> T;
	
	for(int i=0; i<T; i++){
		cin >> N;
		result.push_back(CountCall(N));
	}
	
	for(int i=0; i<T-1; i++){
		cout << result[i].first << ' ' << result[i].second << endl;
	}
	cout << result[T-1].first << ' ' << result[T-1].second << endl;
	
	return 0;
}
