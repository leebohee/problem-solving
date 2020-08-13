#include <iostream>
#include <string>

#define MAX_N 10000

using namespace std;

class MyQueue{
public:
	void push(int x){
		queue[tail++] = x;
	}
	void pop(){
		if(head == tail){
			cout << "-1\n";
		}
		else{
			cout << queue[head++] << '\n';
		}
	}
	int size(){
		return (tail-head);
	}
	bool empty(){
		if(tail == head) return true;
		else return false;
	}
	int front(){
		if(tail == head) return -1;
		else return queue[head];
	}
	int back(){
		if(tail == head) return -1;
		else return queue[tail-1];
	}
	MyQueue(): head(0), tail(0) {};
private:
	int queue[MAX_N];
	int head;
	int tail;
};

int main(){
	int N, x;
	MyQueue q;
	string cmd;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;
		if(cmd == "push"){
			cin >> x;
			q.push(x);
		}
		else if(cmd == "pop"){
			q.pop();
		}
		else if(cmd == "size"){
			cout << q.size() << '\n';
		}
		else if(cmd == "empty"){
			cout << (q.empty()? "1\n" : "0\n");
		}
		else if(cmd == "front"){
			cout << q.front() << '\n';
		}
		else{
			cout << q.back() << '\n';
		}
	}
	return 0;
}