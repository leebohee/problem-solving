#include <iostream>

#define N 4

using namespace std;

int arr[N];
int candidates[N] = {1, 2, 3, 4};
bool possible[N] = {true, };

void print_arr(){
	for(int i=0; i<N; i++) cout << arr[i] << ' ';
	cout << '\n';
}

void permutation(int k, int n){
	if(k == n){
		print_arr();
		return;
	}
	for(int i=0; i<N; i++){
		if(possible[i]){
			arr[k] = candidates[i];
			possible[i] = false;
			permutation(k+1, n);
			possible[i] = true;
		}
	}
}

int main(){
	for(int i=0; i<N; i++) possible[i] = true;
	permutation(0, 4);
	return 0;
}
