#include <iostream>
#include <ctime>
#include <cstdlib>

#define N 10000

using namespace std;

struct node {
	int val1;
	int val2;
	int val3;
} arr[10000];

void print_struct(){
	for(int i=0; i<N; i++){
		cout << i+1 << "th struct : " << arr[i].val1 << ' ' << arr[i].val2 << ' ' << arr[i].val3 << '\n';
	}
}

void swap(struct node* a, struct node* b){
	struct node tmp = *a;
	*a = *b;
	*b = tmp;
}

int compare(const struct node* a, const struct node* b){
	if(a->val1 > b->val1) return 1;
	else if(a->val1 == b->val1){
		if(a->val2 > b->val2) return 1;
		else if(a->val2 == b->val2){
			if(a->val3 >= b->val3) return 1;
			else return -1;
		}
		else return -1;
	}
	else return -1;
}

int median3(int left, int right){
	int mid = left + (right-left)/2;
	int a = arr[left].val1, b = arr[mid].val1, c = arr[right].val1;
	
	if((a < b && b < c) || (c < b && b < a)) return mid;
	else if((b < c && c < a) || (a < c && c < b)) return right;
	else return left;
}

void quick_sort(int start, int end){
	if(start >= end) return;
	
	int left = start, right = end+1;
	int mid = median3(start, end);

	swap(&arr[start], &arr[mid]);
	
	int pivot = arr[left].val1;
	while(left < right){
		do {
			left++;
		} while(left <= end && compare(&arr[left], &arr[start]) < 0);
		do {
			right--;
		} while(right > start && compare(&arr[right], &arr[start]) > 0);
		if(left < right){
			swap(&arr[left], &arr[right]);
		} 
	}			
	swap(&arr[start], &arr[right]);
	quick_sort(start, right-1);
	quick_sort(right+1, end);
}



int main(){
	clock_t start, end;
	
	srand(time(NULL));
	for(int i=0; i<N; i++){
		arr[i].val1 = rand() % N;
		arr[i].val2 = rand() % N;
		arr[i].val3 = rand() % N;
	}
	print_struct();
	printf("\n"); 
	start = clock();
	quick_sort(0, N-1);
	end = clock();
	print_struct();
	printf("RunTime: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}
