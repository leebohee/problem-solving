#include <iostream>

using namespace std;

int Bigger(int a, int b){
	int result = 0, digit1, digit2;
	
	while(a != 0 && b != 0){
		digit1 = a % 10;
		digit2 = b % 10;
		if(digit1 > digit2){ // a is bigger
			b = 0;
			break;
		}
		else if(digit1 < digit2){ // b is bigger
			a = 0;
			break;
		}
		else{
			a = a / 10;
			b = b / 10;
			result = result*10 + digit1;
		}
	}
	while(a != 0){
		result = result*10 + (a % 10);
		a = a / 10;
	}
	while(b != 0){
		result = result*10 + (b % 10);
		b = b / 10;
	}
	return result;
}

int main(){
	int a, b;
	cin >> a >> b;
	cout << Bigger(a, b);
	return 0;
}
