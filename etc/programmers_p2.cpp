#include <string>
#include <vector>
#include <queue>

using namespace std;

int kth_element(const vector<int>& array, int i, int j, int k){
	priority_queue< int, vector<int>, greater<int> > pq(array.begin()+i, array.begin()+j+1); // O(N)

	for(int kk=0; kk<k-1; kk++){ // O(KlogN)
		pq.pop();
	}
	return pq.top();
}
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto command: commands)
        answer.push_back(kth_element(array, command[0]-1, command[1]-1, command[2]));
    return answer;
}
