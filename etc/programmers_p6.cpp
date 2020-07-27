#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int n = dates.size(), amount = stock;
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
    	if(amount == dates[i]){
            pq.push(supplies[i]);
            supplies[i] = -1;
        }
    	while(amount <= dates[i]){
	        amount += pq.top();
	        pq.pop();
	        answer++;
	        if(amount >= k) return answer;
	    }
        pq.push(supplies[i]);
    }
    while(amount < k){
        amount += pq.top();
        pq.pop();
        answer++;
    }
    return answer;
}
