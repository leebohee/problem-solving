#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct range{
	int start;
	int end;
	range(int s, int e): start(s), end(e) {};
	bool operator<(const range& r){
		if(this->start < r.start) return true;
		else if(this->start == r.start && this->end < r.end) return true;
		else return false;
	}
};

int total_len(int N, vector<range> lines){
	sort(lines.begin(), lines.end());
	range cur(lines[0]);
	int result = 0;
	for(range& line: lines){
		if(line.start <= cur.end) cur.end = max(cur.end, line.end);
		else{
			result += (cur.end-cur.start);
			cur = line;
		}
	}
	result += (cur.end-cur.start);
	return result;
}

int main(){
	int N, s, e;
	scanf("%d", &N);
	vector<range> lines;
	lines.reserve(N);
	for(int i=0; i<N; i++){
		scanf("%d %d", &s, &e);
		lines.emplace_back(s, e);
	}
	printf("%d", total_len(N, move(lines)));
	return 0;
}
