#include <cstdio>

#define MAX_N 10000

using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;
	Node(): val(-1), left(nullptr), right(nullptr) {};
	Node(int v): val(v), left(nullptr), right(nullptr) {};
};

Node* tree;
int preorder[MAX_N];
int N = 0;

Node* buildBST(int start, int end, int index){
	if(start >= N) return nullptr;
	if(start > end) return nullptr;
	Node* n = new Node(preorder[start]);
	if(start == end) return n;

	int mid = start;
	for (int i = start+1; i <= end; i++)
	{
		if(preorder[i] > preorder[start]) break;
		else mid = i;
	}
	n->left = buildBST(start+1, mid, index*2); // left subtree
	n->right = buildBST(mid+1, end, index*2+1); // right subtree
	return n;
}

void postorder(Node* root){
	if(!root) return;
	postorder(root->left); // left subtree
	postorder(root->right); // right subtree
	printf("%d\n", root->val);
}

int main(){
	int x;
	while(scanf("%d", &x) != EOF){
		preorder[N++] = x;
	}

	Node* root = new Node();
	root = buildBST(0, N-1, 1);

	postorder(root);
	return 0;
}