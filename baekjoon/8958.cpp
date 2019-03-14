#include <iostream>
#include <vector>
#include <string>

using namespace std;

int CalculateScore(string result){
	int len = result.length();
	int score = 0, sum = 0;

	for(int i=0; i<len; i++){
		if(result.at(i) == 'O'){
			score++;
			sum += score;
		}	
		else{
			score = 0;
		}
	}
	return sum;
}

int main(){
	int n;
	string str;
	vector <int> result;
	
	cin >> n;
	cin.ignore();
	for(int i=0; i<n; i++){
		getline(cin, str);
		result.push_back(CalculateScore(str));
	}
	
	for(int i=0; i<n-1; i++){
		cout << result[i] << endl;
	}
	cout << result[n-1];
	return 0;
}
