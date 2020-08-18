#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 8

using namespace std;

int N, M;
int nums[MAX];
int prev_perm[MAX];
bool visit[MAX];

void make_perm(int index, vector<int>& perm){
	perm.push_back(nums[index]);
	visit[index] = true;
	if(perm.size() == M){
		for(int i=0; i<M; i++){
			cout << perm[i] << ' ';
		}
		cout << '\n';
	}
	else{
		int visited = -1; // 같은 위치에서 같은 값을 방문했던 적이 있는지 확인하기 위해 이전에 방문했던 수 저장
		for(int i=index+1; i<N; i++){
			if(!visit[i] && visited != nums[i]){
				make_perm(i, perm);
				visited = nums[i];
			}
		}
	}
	visit[index] = false;
	perm.pop_back();
}

int main(){
	cin >> N >> M;

	for(int i=0; i<N; i++){
		cin >> nums[i];
	}

	sort(nums, nums+N);

	vector<int> perm;
	int visited = -1; // 이전에 방문했던 수인지 확인
	for(int i=0; i<N; i++){
		if(visited != nums[i]){
			make_perm(i, perm);
			visited = nums[i];
		}
	}

	return 0;
}