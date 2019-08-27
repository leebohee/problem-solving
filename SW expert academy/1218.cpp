#include <iostream>

#define MAX_LEN 300

using namespace std;

int len;
char str[MAX_LEN];

int is_valid(){
	char stack[MAX_LEN];
	char ch;
	int idx = 0;
	
	for(int i = 0; i < len; i++){
		if(str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<'){
			// push
			stack[idx++] = str[i];
		}
		else{
			// pop
			if(idx <= 0) return 0;
			ch = stack[--idx];
			
			if(str[i] == ')' && ch != '('){
				return 0;
			}
			else if(str[i] == ']' && ch != '['){
				return 0;
			}
			else if(str[i] == '}' && ch != '{'){
				return 0;
			}
			else if(str[i] == '>' && ch != '<'){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	for(int test_case = 1; test_case <= 10; test_case++){
		cin >> len;
		for(int i = 0; i < len; i++){
			cin >> str[i];
		}
		cout << '#' << test_case << ' ' << is_valid() << '\n';
	}
	
	return 0;
}
