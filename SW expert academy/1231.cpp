#include <iostream>

using namespace std;

struct node{
	char val;
	int left;
	int right;
} Nodes[101];

int N;

void inorder(int idx, string str){
	if(idx > N) return;
	inorder(Nodes[idx].left, str);
	cout << Nodes[idx].val;
	inorder(Nodes[idx].right, str);
}

int main(){
	int idx;
	char ch, left, right;
	string str = "";
	for(int t=1; t<=10; t++){
		cin >> N;
		idx = 1;
		while(true){
			cin >> ch;
			if(ch >= '0' && ch <= '9');
			else{
				Nodes[idx].val = ch;
				Nodes[idx].left = idx*2;
				Nodes[idx].right = idx*2 + 1;
				idx++;
				if(idx > N) break;
			}
		}
		cout << '#' << t << ' ';
		inorder(1, str);
		cout << '\n';
	}

	return 0;
}