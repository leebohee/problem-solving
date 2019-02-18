#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node{
	int item;
	struct node* next;
};

class Queue{
	private:
		int len = 0;
		struct node* fn;
		struct node* bn;
	public:
		void push(int x){
			if(len==0){
				fn = new struct node;
				bn = fn;
			}
			else{
				bn->next = new struct node;
				bn = bn->next;	
			}
			bn->item = x;
			bn->next = NULL;
			len++;
		}
		int pop(void){
			if(len>0){
				len--;
				int x = fn->item;
				struct node* n = fn;
				fn = fn->next;
				if(len==0){
					bn = NULL;
				}
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
		int front(void){
			if(len>0){
				return fn->item;
			}
			else{
				return -1;
			}
		}
		int back(void){
			if(len>0){
				return bn->item;
			}
			else{
				return -1;
			}
		}
};

int main(){
	Queue q;
	int N, x;
	string cmd;
	
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> cmd;
		if(cmd.compare("push") == 0){
			cin.ignore();
			cin >> x;
			q.push(x);
		}
		else if(cmd.compare("pop") == 0){
			cout << q.pop() << endl;
		}
		else if(cmd.compare("size") == 0){
			cout << q.size() << endl;
		}
		else if(cmd.compare("empty") == 0){
			cout << q.empty() << endl;
		}
		else if(cmd.compare("front") == 0){
			cout << q.front() << endl;
		}
		else{
			cout << q.back() << endl;
		}
	}
	
	return 0;
}
