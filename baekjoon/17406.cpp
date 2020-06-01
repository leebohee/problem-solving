#include <iostream>

#define MAX_SIZE 50
#define MAX_OPS 6
#define MAX_VAL 5000

using namespace std;

struct rotate_op{
	int r;
	int c;
	int s;
	void init(int r_, int c_, int s_){
		r = r_;
		c = c_;
		s = s_;
	}
} ops[MAX_OPS];

int ret = MAX_VAL;
int K;
int copyA[MAX_SIZE][MAX_SIZE];

class Arr{
public:
	Arr(int n, int m): N(n), M(m){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> A[i][j];
			}
		}
	};
	int apply_ops(int* order){
		int min_val = MAX_VAL, val;

		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				copyA[i][j] = A[i][j];
			}
		}

		for(int i=0; i<K; i++){
			rotate(order[i]);
		}

		for(int i=0; i<N; i++){
			val = 0;
			for(int j=0; j<M; j++){
				val += copyA[i][j];
			}
			min_val = min(min_val, val);
		}

		return min_val;
	}
private:
	int N, M;
	int A[MAX_SIZE][MAX_SIZE];

	void rotate(int op_idx){
		int r1 = ops[op_idx].r - ops[op_idx].s;
		int r2 = ops[op_idx].r + ops[op_idx].s;
		int c1 = ops[op_idx].c - ops[op_idx].s;
		int c2 = ops[op_idx].c + ops[op_idx].s;
		int tmp;

		while(r1 < ops[op_idx].r){
			tmp = copyA[r1][c1];
			for(int i=r1; i<r2; i++){
				copyA[i][c1] = copyA[i+1][c1];
			}
			for(int i=c1; i<c2; i++){
				copyA[r2][i] = copyA[r2][i+1];
			}
			for(int i=r2; i>r1; i--){
				copyA[i][c2] = copyA[i-1][c2];
			}
			for(int i=c2; i>c1; i--){
				copyA[r1][i] = copyA[r1][i-1];
			}
			copyA[r1][c1+1] = tmp;

			r1++;
			r2--;
			c1++;
			c2--;
		}

	}
};


void min_val(int n, Arr& arr){
	static bool select[MAX_OPS] = {false, };
	static int order[MAX_OPS];
	if(n == K){
		ret = min(ret, arr.apply_ops(order));
	}
	else{
		for(int i=0; i<K; i++){
			if(!select[i]){
				select[i] = true;
				order[n] = i;
				min_val(n+1, arr);
				select[i] = false;
			}
		}
	}
}

int main(){
	int N, M, r, c, s;

	cin >> N >> M >> K;

	Arr arr(N, M);
	for(int i=0; i<K; i++){
		cin >> r >> c >> s;
		ops[i].init(r-1, c-1, s);
	}

	min_val(0, arr);
	cout << ret;
	return 0;
}