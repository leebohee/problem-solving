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

void bubble_sort(){
	/* time complexity = O(N^2) */
	/* simple to implement */
	for(int i=N-1; i>0; i--){
		for(int j=0; j<i; j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);	
			}
		}
	}
}

void selection_sort(){
	/* time complexity = O(N^2) */
	/* useful to find k-largest/smallest number */
	for(int i=N-1; i>=0; i--){
		int max = arr[0], idx = 0;
		for(int j=1; j<i; j++){
			if(arr[j] > max){
				max = arr[j];
				idx = j;
			}
		}
		swap(&arr[idx], &arr[i]);
	}
}

void insertion_sort(){
	/* time complexity = O(N^2) */
	/* fast when elements are sorted  -> O(N) */
	for(int i=1; i<=N-1; i++){
		for(int j=i; j>0; j--){
			if(arr[j] < arr[j-1]){
				swap(&arr[j], &arr[j-1]);
			}
			else{
				break;
			}
		}
	}
}

int median3(int start, int end){
	int mid = start + (end - start) / 2;
	int a = arr[start], b = arr[mid], c = arr[end];
	if((a <= b && b <= c) || (c <= b && b <= a)) return b;
	else if((b <= a && a <= c) || (c <= a && a <= b)) return a;
	else return c;
}

void quick_sort(int start, int end){	
	/* time complexity = O(NlogN) */
	/* fast in general */
	if(start >= end) return;
	
	int m = median3(start, end);
	swap(&arr[start], &arr[m]);
	
	int left = start, right = end + 1;
	int pivot = arr[start];
	
	while(left < right){
		do {
			left++;
		} while(left <= end && arr[left] <= pivot);
		do {
			right--;
		} while(right > start && arr[right] > pivot);
		if(left < right){
			swap(&arr[left], &arr[right]);
		}
	}
	swap(&arr[start], &arr[right]);
	quick_sort(start, right - 1);
	quick_sort(right + 1, end);
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
		arr[i] = i;//rand() % N;
	}
	start = clock();
	//bubble_sort();
	//quick_sort(0, N-1);
	//selection_sort();
	//insertion_sort();
	end = clock();
	//print_arr();
	printf("RunTime: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
	free(arr);
	return 0;
}
