#include<iostream>
#include <unordered_set>

#define MAX_N 20

using namespace std;

int region[MAX_N][MAX_N];
int N;
int max_dessert;

bool is_valid(int r, int c){
	if(r < 0 || r >= N || c < 0 || c >= N) return false;
	else return true;
}

int tour(int r, int c, int len1, int len2){
	const static int dr[4] = {1, 1, -1, -1};
	const static int dc[4] = {1, -1, -1, 1};

	unordered_set<int> desserts;
	desserts.insert(region[r][c]);
	for(int i=0; i<len2; i++){			
		int next_r = r + dr[0];
		int next_c = c + dc[0];
		if(!is_valid(next_r, next_c)) return -1;
		if(desserts.find(region[next_r][next_c]) != desserts.end()) return -1;
		desserts.insert(region[next_r][next_c]);

		r = next_r;
		c = next_c;
	}
	for(int i=0; i<len1; i++){
		int next_r = r + dr[1];
		int next_c = c + dc[1];

		if(!is_valid(next_r, next_c)) return -1;
		if(desserts.find(region[next_r][next_c]) != desserts.end()) return -1;
		desserts.insert(region[next_r][next_c]);

		r = next_r;
		c = next_c;
	}
	for(int i=0; i<len2; i++){
		int next_r = r + dr[2];
		int next_c = c + dc[2];

		if(!is_valid(next_r, next_c)) return -1;
		if(desserts.find(region[next_r][next_c]) != desserts.end()) return -1;
		desserts.insert(region[next_r][next_c]);

		r = next_r;
		c = next_c;
	}
	for(int i=0; i<len1-1; i++){
		int next_r = r + dr[3];
		int next_c = c + dc[3];

		if(!is_valid(next_r, next_c)) return -1;
		if(desserts.find(region[next_r][next_c]) != desserts.end()) return -1;
		desserts.insert(region[next_r][next_c]);

		r = next_r;
		c = next_c;
	}
	return desserts.size();
}

void cafe_tour(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int l1 = j, l2 = N-1-j;
			for(int len1=1; len1<=l1; len1++){
				for(int len2=1; len2<=l2; len2++){
					max_dessert = max(max_dessert, tour(i, j, len1, len2));
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin >> region[i][j];
			}
		}
		max_dessert = -1;
		cafe_tour();
		cout << '#' << test_case << ' ' << max_dessert << '\n';
	}
	return 0;
}
