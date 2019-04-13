#include <vector>
#include <utility>
#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

void ClearQueue(queue < vector <int> > &q){
	while(!q.empty()){
		q.pop();
	}
}

class BabyShark {
	private:
		int size;
		int r;
		int c;
	public:
		BabyShark(int _r, int _c){
			size = 2;
			r = _r;
			c = _c;
		}
		int MealTime(int N, vector < vector <int> > map){
			queue < vector <int> > q;
			int second = 0, eat = 0;
			vector <int> cur, tmp;
			
			bool** visit = new bool* [N];
			for(int i=0; i<N; i++){
				visit[i] = new bool [N];
			}
			
			while(true){
				pair <int, int> next = make_pair(N, N);
				int s_next = INT_MAX;
				
				// initialize array checking visit
				for(int i=0; i<N; i++){
					memset(visit[i], false, sizeof(bool)*N);
				}
				
				cur.push_back(r);
				cur.push_back(c);
				cur.push_back(second);
				q.push(cur);
				while(!q.empty()){
					cur = q.front();
					
					// check visiting
					if(visit[cur[0]][cur[1]]){
						q.pop();
						continue;
					}
					visit[cur[0]][cur[1]] = true;
					
					// check minimum distance from baby shark
					if(cur[2] >= s_next) break; 
					
					// up
					if(cur[0] > 0 && map[cur[0]-1][cur[1]] <= size && !visit[cur[0]-1][cur[1]]){ 
						if(map[cur[0]-1][cur[1]] == 0 || map[cur[0]-1][cur[1]] == size){ // pass
							tmp.push_back(cur[0]-1);
							tmp.push_back(cur[1]);
							tmp.push_back(cur[2]+1);
							q.push(tmp);
							tmp.clear();
						}
						else{ // fish 
							if((next.first > cur[0]-1) || (next.first == cur[0]-1 && next.second > cur[1])){
								next.first = cur[0]-1;
								next.second = cur[1];
								s_next = cur[2]+1;
							}
						}
					}
					// left
					if(cur[1] > 0 && map[cur[0]][cur[1]-1] <= size && !visit[cur[0]][cur[1]-1]){ 
						if(map[cur[0]][cur[1]-1] == 0 || map[cur[0]][cur[1]-1] == size){ // pass
							tmp.push_back(cur[0]);
							tmp.push_back(cur[1]-1);
							tmp.push_back(cur[2]+1);
							q.push(tmp);
							tmp.clear();
						}
						else{ // fish 
							if((next.first > cur[0]) || (next.first == cur[0] && next.second > cur[1]-1)){
								next.first = cur[0];
								next.second = cur[1]-1;
								s_next = cur[2]+1;
							}
						}
					}
					// down
					if(cur[0] < N-1 && map[cur[0]+1][cur[1]] <= size && !visit[cur[0]+1][cur[1]]){ 
						if(map[cur[0]+1][cur[1]] == 0 || map[cur[0]+1][cur[1]] == size){ // pass
							tmp.push_back(cur[0]+1);
							tmp.push_back(cur[1]);
							tmp.push_back(cur[2]+1);
							q.push(tmp);
							tmp.clear();
						}
						else{ // fish 
							if((next.first > cur[0]+1) || (next.first == cur[0]+1 && next.second > cur[1])){
								next.first = cur[0]+1;
								next.second = cur[1];
								s_next = cur[2]+1;
							}
						}
					}
					// right
					if(cur[1] < N-1 && map[cur[0]][cur[1]+1] <= size && !visit[cur[0]][cur[1]+1]){ 
						if(map[cur[0]][cur[1]+1] == 0 || map[cur[0]][cur[1]+1] == size){ // pass
							tmp.push_back(cur[0]);
							tmp.push_back(cur[1]+1);
							tmp.push_back(cur[2]+1);
							q.push(tmp);
							tmp.clear();
						}
						else{ // fish 
							if((next.first > cur[0]) || (next.first == cur[0] && next.second > cur[1]+1)){
								next.first = cur[0];
								next.second = cur[1]+1;
								s_next = cur[2]+1;
							}
						}
					}
					q.pop();
				}
				
				if(s_next == INT_MAX){ // no fish to eat
					for(int i=0; i<N; i++){
						delete [] visit[i];
					}
					delete [] visit;
					return second;
				}
				else{
					second = s_next;
					map[r][c] = 0;
					map[next.first][next.second] = 9;
					r = next.first;
					c = next.second;
					eat++;
					if(eat == size){ // baby shark grows
						size++;
						eat = 0;
					}
 				}
				cur.clear();
				ClearQueue(q);
			}
		}
};

int main(){
	int N, x, r, c;
	vector < vector <int> > map;
	vector <int> tmp;
	
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> x;
			tmp.push_back(x);
			if(x == 9){
				r = i;
				c = j;
			}		
		}
		map.push_back(tmp);
		tmp.clear();
	}
	BabyShark bs(r, c);
	cout << bs.MealTime(N, map);
	
	return 0;
}

