#include <cstdio>
#include <queue>

using namespace std;

int main(){
	int N, n;
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int> > min_heap;

	scanf("%d", &N);

	scanf("%d", &n);
	max_heap.push(n);
	printf("%d\n", max_heap.top());
	for(int i=2; i<=N; i++){
		scanf("%d", &n);
		if(max_heap.top() < n) min_heap.push(n);
		else max_heap.push(n);
		
		if(max_heap.size() < min_heap.size()){
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
		if(max_heap.size() > min_heap.size() + 1){
			min_heap.push(max_heap.top());
			max_heap.pop();
		}
		printf("%d\n", max_heap.top());
	}
	return 0;
}
