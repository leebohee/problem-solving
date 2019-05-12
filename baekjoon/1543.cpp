#include <iostream>
#include <vector>

using namespace std;

float NewAvg(vector <float> &score, float highest){
	int size = score.size();
	float sum = 0.0;
	
	for(int i=0; i<size; i++){
		sum = sum + (score[i]/highest)*100;		
	}
	
	return sum / size;
}

int main(){
	vector <float> score;
	float highest = 0.0, x;
	int size;
	
	cin >> size;
	for(int i=0; i<size; i++){
		cin >> x;
		if(x > highest){
			highest = x;
		}
		score.push_back(x);
	}
	cout << NewAvg(score, highest);
	return 0;
}
