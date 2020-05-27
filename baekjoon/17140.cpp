#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define MAX_SIZE 100

using namespace std;

struct element{
	int val;
	int cnt;
	element(int v, int num): val(v), cnt(num) {};
	bool operator <(const element& e){
		if(this->cnt < e.cnt) return true;
		else if(this->cnt == e.cnt && this->val < e.val) return true;
		else return false;
	}
};

class Array{
public:
	Array(int r, int c): target_r(r), target_c(c){
		R = C = 3;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				cin >> arr[i][j];
			}
		}
	};
	bool is_equal(int target){
		if(arr[target_r][target_c] == target) return true;
		else return false;
	}
	void change(){
		if(R >= C) op_row();
		else op_col();
	}

private:
	int target_r;
	int target_c;
	int R, C;
	int arr[MAX_SIZE][MAX_SIZE];

	void op_row(){
		int new_arr[MAX_SIZE][MAX_SIZE] = {0, };
		int max_col = 0, idx, n;
		
		for(int i=0; i<R; i++){
			map<int, int> vals; // (arr value, index in vector)
			vector<element> elements;
			for(int j=0; j<C; j++){
				if(arr[i][j] <= 0) continue;
				auto itr = vals.find(arr[i][j]);
				if(itr == vals.end()){
					vals.insert(make_pair(arr[i][j], elements.size()));
					elements.push_back(element(arr[i][j], 1));
				}
				else{
					elements[itr->second].cnt += 1;
				}
			}
			sort(elements.begin(), elements.end());
			idx = 0;
			n = elements.size();
			for(int j=0; j<n; j++){
				new_arr[i][idx++] = elements[j].val;
				new_arr[i][idx++] = elements[j].cnt;
			}
			max_col = max(max_col, idx);
		}
		C = max_col;
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				arr[i][j] = new_arr[i][j];
			}
		}
	}
	void op_col(){
		int new_arr[MAX_SIZE][MAX_SIZE] = {0, };
		int max_row = 0, idx, n;
		
		for(int i=0; i<C; i++){
			map<int, int> vals; // (arr value, index in vector)
			vector<element> elements;
			for(int j=0; j<R; j++){
				if(arr[j][i] <= 0) continue;
				auto itr = vals.find(arr[j][i]);
				if(itr == vals.end()){
					vals.insert(make_pair(arr[j][i], elements.size()));
					elements.push_back(element(arr[j][i], 1));
				}
				else{
					elements[itr->second].cnt += 1;
				}
			}
			sort(elements.begin(), elements.end());
			idx = 0;
			n = elements.size();
			for(int j=0; j<n; j++){
				if(idx >= MAX_SIZE) break; // out-of-range
				new_arr[idx++][i] = elements[j].val;
				new_arr[idx++][i] = elements[j].cnt;
			}
			max_row = max(max_row, idx);
		}
		R = max_row;
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				arr[i][j] = new_arr[i][j];
			}
		}
	}
};

int main(){
	int r, c, k, t = 0;

	cin >> r >> c >> k;
	Array arr(r-1, c-1);


	while(!arr.is_equal(k)){
		t++;
		if(t > 100){
			cout << -1;
			return 0;
		}
		arr.change();
	}
	cout << t;
	return 0;
}
