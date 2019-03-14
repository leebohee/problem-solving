#include <iostream>
#include <cstring>

using namespace std; 

int CountWords(string str){
	int len = str.length();
	int cnt = 0;
	// blank string
	if(str.compare(" ")==0){
		return 0;
	}
	for(int i=1; i<len-1; i++){
		if(str.at(i)==' '){
			cnt++;
		}	
	}
	cnt++;
	
	return cnt;
}

int main(){
	char s[1000001];
	fgets(s, 1000001, stdin);
	int len = strlen(s);
	// remove newline character
	if(len>0 && s[len-1]=='\n') s[len-1]='\0';
	string str(s);
	cout << CountWords(str);
	return 0;
}
