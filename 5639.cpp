#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector <int> preorder;

void PostTraversal(int idx1, int idx2){
	int size = idx2-idx1+1;
	int i;

	if(size == 1){ // root
		cout << preorder[idx1] << '\n';
		return;
	}
	// find division line
	for(i=idx1+1; i<=idx2; i++){
		if(preorder[i]>preorder[idx1]){
			break;
		}
	}
	int idx=i-1;
	
	if(idx != idx1){ // not all right subtree
		PostTraversal(idx1+1, idx);
	}
	if(idx != idx2){ // not all left stubtree
		PostTraversal(idx+1, idx2);
	}
	
	cout << preorder[idx1] << '\n';
}

int main(){
	int v;
	
	while(scanf("%d", &v) != EOF){
		preorder.push_back(v);
	}
	
	int size = preorder.size();
	PostTraversal(0, size-1);

	return 0;
}

