#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node {
	int left = 0;
	int right = 0;
};

struct node tree[1000001];

void Visit(int val){
	cout << val << '\n';
}
vector <int> PostTraversal(int n){
	static vector <int> post_seq;
	
	if(tree[n].left != 0){
		PostTraversal(tree[n].left);
	}
	if(tree[n].right != 0){
		PostTraversal(tree[n].right);
	}
	post_seq.push_back(n);
	
	return post_seq;
}

int main(){
	int parent, child, root;
	
	scanf("%d", &root);

	while(scanf("%d", &child) != EOF){
		parent = root;
		while(true){
			if(parent > child){
				if(tree[parent].left != 0){
					parent = tree[parent].left;
				}
				else{
					tree[parent].left = child;
					break;	
				}
			}
			else{
				if(tree[parent].right != 0){
					parent = tree[parent].right;
				}
				else{
					tree[parent].right = child;
					break;	
				}
 			}
		}
	}
	
	vector <int> postorder = PostTraversal(root);
	int size = postorder.size();
	for(int i=0; i<size-1; i++){
		cout << postorder[i] << '\n';
	}
	cout << postorder[size-1];
	return 0;
}
