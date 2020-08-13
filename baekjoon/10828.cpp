#include <iostream>
#include <string>

#define MAX_N 10000

using namespace std;

class MyStack{
public:
	void push(int x){
		st[n++] = x;
	}
	void pop(){
		if(n == 0){
			cout << "-1\n";
		}
		else{
			cout << st[n-1] << '\n';
			n--;
		}
	}
	int size(){
		return n;
	}
	bool empty(){
		if(n == 0) return false;
		else return true;
	}
	int top(){
		if(n == 0) return -1;
		else return st[n-1];
	}
	MyStack(): n(0) {};
private:
	int st[MAX_N];
	int n;
};

int main(){
	int N, x;
	MyStack st;
	string cmd;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cmd;
		if(cmd == "push"){
			cin >> x;
			st.push(x);
		}
		else if(cmd == "pop"){
			st.pop();
		}
		else if(cmd == "size"){
			cout << st.size() << '\n';
		}
		else if(cmd == "empty"){
			cout << (st.empty()? "0\n" : "1\n");
		}
		else{
			cout << st.top() << '\n';
		}
	}
	return 0;
}