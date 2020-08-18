#include <cstdio>

#define MAX_N 1000001


class DisjointSet{
public:
	DisjointSet(int n_){
		n = n_;
		parent = new int [n+1];
		for(int i=0; i<=n_; i++) parent[i] = i;
	};

	bool same_set(int a, int b){
		if(find(a) == find(b)) return true;
		else return false;
	}

	int find(int a){
		if(parent[a] == a) return a;
		else return parent[a] = find(parent[a]);
	}

	void union_(int a, int b){
		int rootA = find(a);
		int rootB = find(b);
		parent[rootB] = rootA;
	}

private:
	int* parent;
	int n;
};


int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	DisjointSet ds(n);
	for(int i=0; i<m; i++){
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
		if(op == 0){
			ds.union_(a, b);
		}
		else{
			if(ds.same_set(a, b)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}