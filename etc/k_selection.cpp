#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int N;
int* arr;

void swap(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void k_largest(int k){
	int limit = N - k;
	for(int i=N-1; i>=limit; i--){
		int max = arr[0], idx = 0;
		for(int j=1; j<i; j++){
			if(arr[j] > max){
				max = arr[j];
				idx = j;
			}
		}
		swap(&arr[idx], &arr[i]);
	}
	cout << "k largest element : " << arr[limit] << endl;
}

void print_arr(){
	for(int i=0; i<N; i++){
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main(){
	clock_t start, end;
	
	cin >> N;	
	arr = new int [N];
	srand(time(NULL));
	for(int i=0; i<N; i++){
		arr[i] = rand() % N;
	}
	print_arr();
	start = clock();
	//bubble_sort();
	//quick_sort(0, N-1);
	k_largest(3);
	end = clock();
	//print_arr();
	printf("RunTime: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
	free(arr);
	return 0;
}
