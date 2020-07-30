#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define MAX_K 100000

using namespace std;

struct thing{
	int w;
	int v;
	thing(int w_, int v_): w(w_), v(v_) {};
	bool operator<(const thing& th){
		if(this->v == th.v) return this->w > th.w;
		else return this->v > th.v;
	}
};

int measure(vector<thing>& things, int weight, int value, int idx, int K){
	if(weight > K) return INT_MIN;
	if(idx >= things.size()) return value;
	int contain = measure(things, weight+things[idx].w, value+things[idx].v, idx+1, K);
	int not_contain = measure(things, weight, value, idx+1, K);
	int ret = max(contain, not_contain);
	return ret;
}

int max_value_bf(vector<thing>& things, int K){
	// sort by value
	sort(things.begin(), things.end());
	return measure(things, 0, 0, 0, K);
}

int max_value(vector<thing>& things, int K){
	int n = things.size();
	int dp[MAX_K+1] = {0, };
	for(int i=0; i<n; i++){
		for(int k=K; k>=1; k--){ // for(int k=1; k<=K; k++)
			if(things[i].w <= k){
				dp[k] = max(dp[k], dp[k-things[i].w]+things[i].v);
			}
		}
	}
	return dp[K];
}

int main(){
	int N, K, W, V;
	vector<thing> things;
	cin >> N >> K;
	for(int i=0; i<N; i++){
		cin >> W >> V;
		things.emplace_back(W, V);
	}
	cout << max_value(things, K);
	return 0;
}
