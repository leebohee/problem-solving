#include<iostream>

#define SIZE 100
#define QSIZE 10000

using namespace std;

int map[SIZE][SIZE];
bool visit[SIZE][SIZE] = { false, };
int queue[QSIZE][2] = { {0, 0},  };
int front = 0, back = 0;

bool isFull() {
	if ((back + 1) % QSIZE == front) {
		return true;
	}
	else {
		return false;
	}
}

bool isEmpty() {
	if (front == back) {
		return true;
	}
	else {
		return false;
	}
}
void enqueue(int r, int c) {
	if (isFull()) {
		cout << "enqueue failed\n";
		return;
	}
	back = (back + 1) % QSIZE;
	queue[back][0] = r;
	queue[back][1] = c;
}

int* dequeue() {
	if (isEmpty()) {
		cout << "dequeue failed\n";
		return nullptr;
	}
	front = (front + 1) % QSIZE;
	return queue[front];
}

bool is_valid(int r, int c){
	if(r < 0 || r > SIZE-1 || c < 0 || c > SIZE-1) return false;
	else return true;
}

int possible(int sr, int sc, int er, int ec) {
	int r, c, next_r, next_c;
	int dr[4] = {-1, 1, 0, 0};
	int dc[4] = {0, 0, -1, 1};
	
	enqueue(sr, sc);
	visit[sr][sc] = true;
	while (!isEmpty()) {
		int* cur = dequeue();
		r = cur[0];
		c = cur[1];
		if (map[r][c] == 3) return 1;
		for(int i = 0; i < 4; i++){
			next_r = r + dr[i];
			next_c = c + dc[i];
			if(is_valid(next_r, next_c) && map[next_r][next_c] != 1 && !visit[next_r][next_c]){
				visit[next_r][next_c] = true;
				enqueue(next_r, next_c);
			}
		}
	}
	return 0;
}

int main(int argc, char** argv)
{
	int test_case, x, sr, sc, er, ec;
	int T = 10;
	char ch;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/

	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////
		cin >> x;
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				cin >> ch;
				map[i][j] = ch - '0';
				if (map[i][j] == 2) {
					sr = i;
					sc = j;
				}
				else if (map[i][j] == 3) {
					er = i;
					ec = j;
				}
			}
		}
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				visit[i][j] = false;
			}
		}
        front = 0;
        back = 0;
		cout << '#' << test_case << ' ' << possible(sr, sc, er, ec) << '\SIZE';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
