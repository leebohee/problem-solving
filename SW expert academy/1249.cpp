#include<iostream>
#include <climits>

#define MAX_SIZE 40000

using namespace std;

int N;
char map[100][100];
int heap[MAX_SIZE][3];
int heapSize = 0;

void heapInit(void)
{
	heapSize = 0;
}

int heapPush(int r, int c, int t)
{
	if (heapSize + 1 > MAX_SIZE)
	{
		printf("queue is full!");
		return 0;
	}

	heap[heapSize][0] = r;
	heap[heapSize][1] = c;
	heap[heapSize][2] = t;

	int current = heapSize;
	while (current > 0 && heap[current][2] < heap[(current - 1) / 2][2]) 
	{
		int temp = heap[(current - 1) / 2][0];
		heap[(current - 1) / 2][0] = heap[current][0];
		heap[current][0] = temp;

		temp = heap[(current - 1) / 2][1];
		heap[(current - 1) / 2][1] = heap[current][1];
		heap[current][1] = temp;

		temp = heap[(current - 1) / 2][2];
		heap[(current - 1) / 2][2] = heap[current][2];
		heap[current][2] = temp;

		current = (current - 1) / 2;
	}

	heapSize = heapSize + 1;

	return 1;
}

int heapPop(int *r, int *c, int *t)
{
	if (heapSize <= 0)
	{
		return -1;
	}

	*r = heap[0][0];
	*c = heap[0][1];
	*t = heap[0][2];
	heapSize = heapSize - 1;

	heap[0][0] = heap[heapSize][0];
	heap[0][1] = heap[heapSize][1];
	heap[0][2] = heap[heapSize][2];

	int current = 0;
	while (current * 2 + 1 < heapSize)
	{
		int child;
		if (current * 2 + 2 == heapSize)
		{
			child = current * 2 + 1;
		}
		else
		{
			child = heap[current * 2 + 1][2] < heap[current * 2 + 2][2] ? current * 2 + 1 : current * 2 + 2;
		}

		if (heap[current][2] < heap[child][2])
		{
			break;
		}

		int temp = heap[current][0];
		heap[current][0] = heap[child][0];
		heap[child][0] = temp;

		temp = heap[current][1];
		heap[current][1] = heap[child][1];
		heap[child][1] = temp;

		temp = heap[current][2];
		heap[current][2] = heap[child][2];
		heap[child][2] = temp;

		current = child;
	}
	return 1;
}
bool is_valid(int r, int c){
	if(r < 0 || r >= N || c < 0 || c >= N) return false;
	else return true;
}

int min(int a, int b){
	if(a < b) return a;
	else return b;
}

int recovery(){
	int result = INT_MAX;
	int r, c, t, next_r, next_c;
	int dr[4] = {-1, 1, 0, 0};
	int dc[4] = {0, 0, -1, 1};
	int memo[100][100];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++) memo[i][j] = INT_MAX;
	}
	heapInit(); // priority queue init
	heapPush(0, 0, 0);
	while(heapSize > 0){ // priority queue is not empty
		heapPop(&r, &c, &t);
		if(r == N-1 && c == N-1){ // goal
			result = min(result, t);
		}
		else{
			for(int i=0; i<4; i++){
				next_r = r + dr[i];
				next_c = c + dc[i];
				if(is_valid(next_r, next_c) && result > t+(map[next_r][next_c]-'0') && memo[next_r][next_c] > t+(map[next_r][next_c]-'0')){
					heapPush(next_r, next_c, t+(map[next_r][next_c]-'0'));
					memo[next_r][next_c] = t+(map[next_r][next_c]-'0');
				}
			}
		}
	}
	return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin >> map[i][j];
			}
		}
		cout << '#' << test_case << ' ' << recovery() << '\n';
	}
	return 0;
}