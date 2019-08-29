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
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/

	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 �� �κп� �������� �˰��� ������ ���ϴ�.
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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
