#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n, k;
int cards[10];
bool visited[10];
unordered_set<int> nums;

void dfs(int index, vector<int>& selected){
	selected.push_back(cards[index]);
	visited[index] = true;
	if(selected.size() == k){
		int num = selected[0];
		for (int i = 1; i < k; i++)
		{
			if(selected[i] >= 10) num = num * 100;
			else num = num * 10;
			num += selected[i];
		}
		nums.insert(num);
	}
	else{
		for(int i=0; i<n; i++){
			if(!visited[i]) dfs(i, selected);
		}
	}
	visited[index] = false;
	selected.pop_back();
}

int main(){
	vector<int> selected;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> cards[i];
	}
	for (int i = 0; i < n; i++)
	{
		dfs(i, selected);
	}
	cout << nums.size();

	return 0;
}