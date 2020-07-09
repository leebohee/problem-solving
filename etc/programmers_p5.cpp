#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<int> adj[n+1];
    bool visit[n+1];
    queue<int> q;
    
    visit[1] = true;
    for(int i=2; i<=n; i++){
        visit[i] = false;
    }
    for(const auto& e: edge){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
        if(e[0] == 1){
            q.push(e[1]);
            visit[e[1]] = true;
        }
        else if(e[1] == 1){
            q.push(e[0]);
            visit[e[0]] = true;   
        }
    }
    
    int cnt;
    while(!q.empty()){
        cnt = q.size();
        for(int i=0; i<cnt; i++){
            int node = q.front();
            q.pop();
            for(int next: adj[node]){
                if(!visit[next]){
                    q.push(next);
                    visit[next] = true;
                }
            }
        }
    }
    return cnt;
}
