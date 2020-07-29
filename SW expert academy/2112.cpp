#include<iostream>
#include <vector>
#include <utility>

#define MAX_D 13
#define MAX_W 20
using namespace std;

int films[MAX_D][MAX_W];
int copy_films[MAX_D][MAX_W];
int D, W, K;

bool pass(){
	for(int j=0; j<W; j++){
		int start = 0, end = 0;
		bool passed = false;
		while(end < D){
			if(copy_films[start][j] == copy_films[end][j]) end++;
			else{
				if(end-start >= K){
					passed = true;
					break;
				}
				else{
					start = end;
				}
			}
		}
		if(!passed && end-start < K) return false;
	}
	
	return true;
}

bool process(int n, int idx, int choose[][2], int num){
	if(n == num){
		for(int i=0; i<D; i++){
			for(int j=0; j<W; j++){
				copy_films[i][j] = films[i][j];
			}
		}
		for(int c=0; c<n; c++){
			int i = choose[c][0];
			for(int j=0; j<W; j++){
				copy_films[i][j] = choose[c][1];
			}
		}
		return pass();
	}
	if(num + (D - idx) < n) return false;
	choose[num][0] = idx;
	choose[num][1] = 0;
	if(process(n, idx+1, choose, num+1)) return true; // A
	
	choose[num][1] = 1;
	if(process(n, idx+1, choose, num+1)) return true; // B
	
	if(process(n, idx+1, choose, num)) return true; // X

	return false;
}

int min_process(){
	for(int i=0; i<=K; i++){
		int arr[K][2];
		if(process(i, 0, arr, 0)) return i;
	}
	return 0;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> D >> W >> K;
		for(int i=0; i<D; i++){
			for(int j=0; j<W; j++){
				cin >> films[i][j];
			}
		}
		cout << '#' << test_case << ' ' << min_process() << '\n';
	}
	return 0;
}
