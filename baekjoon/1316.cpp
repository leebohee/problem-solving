#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <unordered_map>

using namespace std;

bool GroupWord(string str){
	unordered_map <char, int> m;
	int len = str.length();

	for(int i=0; i<len; i++){
		auto itr = m.find(str.at(i));
		
		if(itr == m.end()){		
			m.insert(make_pair(str.at(i), i));
		}
		else{
			if(itr->second == i-1){
				itr->second = i;
			}
			else{
				return false;
			}
		}
	}
	return true;	
}

int CountGroupWords(int N, vector <string> str){
	int cnt = 0;
	
	for(int i=0; i<N; i++){
		if(GroupWord(str[i])){
			cnt++;
		}	
	}
	
	return cnt;
}

int main(){
	int N;
	vector <string> strs;
	string str;
	
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> str;
		strs.push_back(str);
	}
	
	cout << CountGroupWords(N, strs);
	
	return 0;
}
