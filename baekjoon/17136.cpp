#include <iostream>

#define N 10

using namespace std;

int paper[N][N];
bool covered[N][N];
int total_num = 0, result = 26;

bool valid(int r, int c){
	if(r < 0 || r >= N || c < 0 || c >= N) return false;
	else if(!paper[r][c]) return false;
	else return true;
}

bool cover(int r, int c, int n){
	for(int i=r; i<r+n; i++){
		for(int j=c; j<c+n; j++){
			if(covered[i][j]) return false;
		}
	}
	for(int i=r; i<r+n; i++){
		for(int j=c; j<c+n; j++){
			covered[i][j] = true;
		}
	}
	return true;
}

void uncover(int r, int c, int n){
	for(int i=r; i<r+n; i++){
		for(int j=c; j<c+n; j++){
			covered[i][j] = false;
		}
	}
}

void test(int rr, int cc){
	int r, c, n;
	static int paper_cnt[5] = {5, 5, 5, 5, 5};
	static int used = 0, num_covered = 0;
	
	if(num_covered == total_num){
		result = min(result, used);
		return;
	}

	if(result-1 <= used) return;

	for(int i=rr; i<N; i++){
		for(int j=0; j<N; j++){
			if(!covered[i][j]){
				for(r=i; r<N; r++){
					if(covered[r][j]) break;
				}
				for(c=j; c<N; c++){
					if(covered[i][c]) break;
				}

				n = min(r-i, c-j);
				n = min(n, 5);
				
				
				for(int k=n; k>0; k--){
					if(paper_cnt[k-1] > 0){
						if(!cover(i, j, k)) continue;
						paper_cnt[k-1]--;
						used++;
						num_covered += (k*k);
						test(i, j);
						num_covered -= (k*k);
						used--;
						paper_cnt[k-1]++;
						uncover(i, j, k);
					}					
				}
				return;
			}
		}
	}
}

int main(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> paper[i][j];
			if(paper[i][j]){
				total_num++;
				covered[i][j] = false;
			}
			else{
				covered[i][j] = true;
			}
		}
	}

	test(0, 0);
	cout << (result <= 25? result : -1);
}