#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool VPS(string str){
	int len = str.length();
	stack <bool> s;
	
	for(int i=0; i<len; i++){
		if(str.at(i) == '('){
			s.push(true);
		}
		else if(str.at(i) == ')'){
			if(s.empty()){
				return false;
			}
			else{
				s.pop();
			}
		}
	}
	
	return (s.empty()? true : false);
}

int main(){
	int T;
	string str;
	vector <bool> result;
	
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> str;
		result.push_back(VPS(str));
	}
	
	for(int i=0; i<T-1; i++){
		cout << (result[i]? "YES" : "NO") << endl;
	}
	cout << (result[T-1]? "YES" : "NO");
	
	return 0;
}
