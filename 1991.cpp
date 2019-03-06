#include <iostream>

using namespace std;

class Node {
	public:
		char val;
		Node* left;
		Node* right;
		
		Node(char _val){
			val = _val;
			left = NULL;
			right = NULL;
		}	
};

class Btree {
	public:
		Node* root;
		
		Btree(){
			root = new Node('A');
		}
		
		Node* FindNode(Node* n, char val){
			Node* tmp;
			if(n != NULL){
				if(n->val == val){
					return n;
				}
				else{
					tmp = FindNode(n->left, val);
					if(tmp != NULL){
						return tmp;
					}
					tmp = FindNode(n->right, val);
					if(tmp != NULL){
						return tmp;
					}
				}
			}
			return NULL;
		}
		
		void AddNode(char val, char left, char right){
			Node* tmp = FindNode(root, val);

			if(left != '.'){
				tmp->left = new Node(left);
			}
			if(right != '.'){
				tmp->right = new Node(right);
			}
		}
		
		void ClearTree(Node* n){
			if(n != NULL){
				ClearTree(n->left);
				ClearTree(n->right);
				delete n;
			}	
		}	
};

void Visit(Node* n){
	cout << (n->val);
}

// left -> root -> right
void Inorder(Node* n){
	if(n != NULL){
		Inorder(n->left);
		Visit(n);
		Inorder(n->right);	
	}
}

// root -> left -> right
void Preorder(Node* n){
	if(n != NULL){
		Visit(n);
		Preorder(n->left);
		Preorder(n->right);	
	}
}

// left -> right -> root
void Postorder(Node* n){
	if(n != NULL){
		Postorder(n->left);
		Postorder(n->right);
		Visit(n);
	}
}

int main(){
	int N;
	char val, left, right;
	Btree bt;
	
	cin >> N;
	
	// make tree
	for(int i=0; i<N; i++){
		cin >> val >> left >> right;
		bt.AddNode(val, left, right);
	}
	
	Preorder(bt.root);
	cout << endl;
	Inorder(bt.root);
	cout << endl;
	Postorder(bt.root);
	
	bt.ClearTree(bt.root);
	
	return 0;
}
