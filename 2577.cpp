#include <iostream>
#include <vector>

using namespace std;

vector <int> CountNumbers(int A, int B, int C, vector <int> &result){
	int product = A*B*C;
	
	// initialize result array
	for(int i=0; i<10; i++){
		result[i]=0;
	}
	
	// count
	do {
		result[product%10]++;
		product = product/10;
	} while(product != 0);
	
	return result;
}

int main(){
	int A, B, C;
	cin >> A >> B >> C;
	vector <int> result(10);
	
	result=CountNumbers(A, B, C, result);
	
	for(int i=0; i<9; i++){
		cout << result[i] <<endl;
	}
	cout << result[9];
	
	return 0;
}
