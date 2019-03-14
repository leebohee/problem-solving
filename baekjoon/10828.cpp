#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node{
	int item;
	struct node* next;
};

class Stack{
	private:
		int len = 0;
		struct node* s;
	public:
		void push(int x){
			struct node* n = new struct node;
			n->item = x;
			n->next = s;
			s = n;
			len++;
		}
		int pop(void){
			if(len>0){
				len--;
				int x = s->item;
				struct node* n = s;
				s = s->next;
				delete n;
				return x;
			}
			else{
				return -1;
			}
		}
		int size(void){
			return len;
		}
		int empty(void){
			if(len>0){
				return 0;
			}
			else{
				return 1;
			}
		}
		int top(void){
			if(len>0){
				return s->item;
			}
			else{
				return -1;
			}
		}
};

int main(){
	Stack s;
	int N, x;
	string cmd;
	
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> cmd;
		if(cmd.compare("push") == 0){
			cin.ignore();
			cin >> x;
			s.push(x);
		}
		else if(cmd.compare("pop") == 0){
			cout << s.pop() << endl;
		}
		else if(cmd.compare("size") == 0){
			cout << s.size() << endl;
		}
		else if(cmd.compare("empty") == 0){
			cout << s.empty() << endl;
		}
		else{
			cout << s.top() << endl;
		}
	}
	
	return 0;
}
