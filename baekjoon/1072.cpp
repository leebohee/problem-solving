#include <iostream>
#include <climits>
using namespace std;

int min_games(long long X, long long Y){
	long long low = 1, high = INT_MAX;
	long long perc = Y * 100 / X;
	long long games = -1;
	while(low <= high){
		long long mid = low + (high-low) / 2;
		long long new_perc = (Y + mid) * 100 / (X + mid);
		if(new_perc == perc){
			low = mid + 1;
		}
		else{
			games = mid;
			high = mid - 1;
		}
	}
	return games;
}

int main(){
	long long X, Y;

	cin >> X >> Y;

	cout << min_games(X, Y);
	return 0;
}