#include <iostream>

using namespace std;

int FindBackNumber(int N){
	int back_3, back_5;
	
	back_5 = N/5;
	if(N%5 == 0){
		return back_5;
	}
	// prevent for N being negative
	if(N/5 != 0){
		N-=5*back_5;
	}
	while(back_5 >= 0){
		if(N%3 == 0){
			back_3 = N/3;
			return (back_3+back_5);
		}
		else{
			back_5--;
			N+=5;
		}
	}
	return -1;
}

int main(){
	int N;
	cin >> N;
	cout << FindBackNumber(N);
	
	return 0;
}
