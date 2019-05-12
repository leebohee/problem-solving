#include <iostream>

using namespace std;

int main(){
	string str;
	int len, lines, left;
	
	cin >> str;
	len = str.length();
	lines = len / 10;
	left = len % 10;
	for(int i=0; i<lines; i++){
		cout << str.substr(i*10, 10) << '\n';
	}
	cout << str.substr(lines*10, left);
	return 0;
}
