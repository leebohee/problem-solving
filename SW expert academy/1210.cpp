#include <iostream>
#include <cstring>

#define SIZE 100

using namespace std;

int startPoint(int* map[], int endR, int endC){
	while(endR > 0){
		if(endC > 0 && map[endR][endC-1] == 1){
			while(true){	
				endC = endC - 1;
				if(map[endR-1][endC] == 1){
					break;
				}	
			}
		}
		else if(endC < SIZE-1 && map[endR][endC+1] == 1){
			while(true){	
				endC = endC + 1;
				if(map[endR-1][endC] == 1){
					break;
				}	
			}
		}
		endR = endR - 1;
	}
	return endC;
}

int main(){
	int** map;
	int x, c;
	
	map = new int* [SIZE];
	for(int i=0; i<SIZE; i++){
		map[i] = new int [SIZE];
		memset(map[i], 0, sizeof(int)*SIZE);
	}
	for(int i=0; i<10; i++){
		cin >> x;	
		for(int j=0; j<SIZE; j++){
			for(int k=0; k<SIZE; k++){
				cin >> map[j][k];
			}
        }
		for(int j=0; j<SIZE; j++){
			if(map[SIZE-1][j] == 2){
				c = j;
				break;
			}
		}
		cout << '#' << i+1 << ' ' << startPoint(map, SIZE-1, c) << '\n';
	}	
	for(int i=0; i<SIZE; i++){
		delete [] map[i];
	}
	delete [] map;
	return 0;
}
