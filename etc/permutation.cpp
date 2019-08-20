#include <iostream>

using namespace std; 

int main(){
	int arr[] = {1, 2, 3};
	for(int a=0; a<3; a++){
		for(int b=0; b<3; b++){
			if(a == b) continue;
			for(int c=0; c<3; c++){
				if(a == c || b == c) continue;
				cout << '(' << arr[a] << ", " << arr[b] << ", " << arr[c] << ")\n";
			}
		}
	}
	return 0;
}
