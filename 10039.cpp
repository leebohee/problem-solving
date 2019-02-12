#include <iostream>

using namespace std;

int Avg(int* scores){
	int sum = 0;
	for(int i=0; i<5; i++){
		if(scores[i]<40){
			sum += 40;
		}
		else{
			sum += scores[i];
		}
	}
	return sum/5;
}

int main(){
	int scores[5];
	
	for(int i=0; i<5; i++){
		cin >> scores[i];
	}
	cout << Avg(scores);
	return 0;
}
