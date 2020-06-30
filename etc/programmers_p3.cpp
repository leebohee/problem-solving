#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool can_convert(string str1, string str2){
	int len = str1.length();
	bool diff = false;
	for(int i=0; i<len; i++){
		if(str1[i] != str2[i]){
			if(diff) return false;
			else diff = true;
		}
	}
	return true;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int n = words.size();
    // build hash table
    unordered_map<string, vector<int> > umap; // index in words
    for(int i=0; i<n; i++) umap.emplace(words[i], vector<int>());
    for(int i=0; i<n; i++){
    	auto itr1 = umap.find(words[i]);
    	for(int j=i+1; j<n; j++){
    		if(can_convert(words[i], words[j])){
    			auto itr2 = umap.find(words[j]);
    			itr1->second.push_back(j);
    			itr2->second.push_back(i);
    		}
    	}
    }
    // BFS
    queue<pair<string, int> > q;
    bool visit[n];
	for(int i=0; i<n; i++){
		visit[i] = false;
		if(can_convert(begin, words[i])){
			q.push({words[i], 1});
		}
    }
    while(!q.empty()){
    	string str;
    	int level;
    	tie(str, level) = q.front();
    	if(str == target) return level;

    	auto itr = umap.find(str);
    	for(int next: itr->second){
    		if(!visit[next]){
    			q.push({words[next], level+1});
    			visit[next] = true;
    		}
    	}
    	q.pop();
    }
    return 0;
}
