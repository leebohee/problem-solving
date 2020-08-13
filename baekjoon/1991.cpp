#include <iostream>

#define MAX_N 26

using namespace std;

struct Node{
	char val;
	int left;
	int right;
	Node(): val(-1), left(-1), right(-1) {};
};

int N;
Node tree[MAX_N];

void preorder(int root){
	cout << tree[root].val;
	if(tree[root].left >= 0) preorder(tree[root].left);
	if(tree[root].right >= 0) preorder(tree[root].right);
}

void inorder(int root){
	if(tree[root].left >= 0) inorder(tree[root].left);
	cout << tree[root].val;
	if(tree[root].right >= 0) inorder(tree[root].right);
}

void postorder(int root){
	if(tree[root].left >= 0) postorder(tree[root].left);
	if(tree[root].right >= 0) postorder(tree[root].right);
	cout << tree[root].val;
}

int main(){
	char parent, left, right;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> parent >> left >> right;
		tree[parent-'A'].val = parent;
		if(left != '.') tree[parent-'A'].left = left-'A';
		if(right != '.') tree[parent-'A'].right = right-'A';
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);

	return 0;
}