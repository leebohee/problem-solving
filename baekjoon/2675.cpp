#include <string>
#include <iostream>

using namespace std;

string repeatStr(string S, int R){
	string new_str = "";
	int len = S.length();
	
	for(int i=0; i<len; i++){
		new_str += string(R, S.at(i));
	}
	
	return new_str;
}

int main(){
	int N, R;
	string str;
	
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> R >> str;
		cout << repeatStr(str, R) << endl;
	}
	return 0;
}
