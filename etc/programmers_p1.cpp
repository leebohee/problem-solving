#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    vector< unordered_set<int> > nth_set;
	int n = 0, num=0;
    
	while(n <= 8){
		unordered_set<int> cur_set;
		num = num*10 + N;
		cur_set.insert(num);
		for(int i=0; i<n; i++){ // nth_set[i]
			for(int a: nth_set[i]){
				for(int b: nth_set[n-1-i]){
					cur_set.insert(a+b);
					cur_set.insert(a-b);
					cur_set.insert(a*b);
					if(b != 0) cur_set.insert(a/b);
				}
			}
		}
		n++;
		if(cur_set.find(number) != cur_set.end()) return n;
		nth_set.push_back(cur_set);
	}
	return -1;
}
