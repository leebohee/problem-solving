#include <iostream>
#include <cstring>

using namespace std;

void findPosition(string str, int* pos){
	int len = str.length();
	
	for(int i=0; i<len; i++){
		if(pos[str.at(i)-'a'] == -1){
			pos[str.at(i)-'a'] = i;
		}
	}
}

int main(){
	string str;
	int pos[26];
	memset(pos, -1, sizeof(int)*26);
	
	cin >> str;
	findPosition(str, pos);
	
	for(int i=0; i<26; i++){
		cout << pos[i] << ' ';
	}
	cout << endl;
	
	return 0;
}
