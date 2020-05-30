#include <iostream>

#define CUBE_SIZE 3
using namespace std;

enum {UP, DOWN, FRONT, BACK, LEFT, RIGHT};

class Cube{
public:
	Cube(){
		char colors[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
		for(int i=0; i<6; i++){
			for(int j=0; j<CUBE_SIZE; j++){
				for(int k=0; k<CUBE_SIZE; k++){
					cube[i][j][k] = colors[i];
				}
			}
		}
	}
	void rotate(char side, bool clockwise=true){
		char line0[CUBE_SIZE], line1[CUBE_SIZE], line2[CUBE_SIZE], line3[CUBE_SIZE];
		switch(side){
			case 'U':
				if(clockwise){
					for(int i=0; i<CUBE_SIZE; i++){
						line0[i] = cube[BACK][CUBE_SIZE-1][i];
						line1[CUBE_SIZE-i-1] = cube[RIGHT][i][0];
						line2[i] = cube[FRONT][0][i];
						line3[CUBE_SIZE-i-1] = cube[LEFT][i][CUBE_SIZE-1];
					}
					shift(line0, line1, line2, line3);
					for(int i=0; i<CUBE_SIZE; i++){
						cube[BACK][CUBE_SIZE-1][i] = line0[i];
						cube[RIGHT][i][0] = line1[i];
						cube[FRONT][0][i] = line2[i];
						cube[LEFT][i][CUBE_SIZE-1] = line3[i];
					}
				}
				else{
					for(int i=0; i<CUBE_SIZE; i++){
						line0[i] = cube[LEFT][i][CUBE_SIZE-1];
						line1[CUBE_SIZE-i-1] = cube[FRONT][0][i];
						line2[i] = cube[RIGHT][i][0];
						line3[CUBE_SIZE-i-1] = cube[BACK][CUBE_SIZE-1][i];
					}
					shift(line0, line1, line2, line3);
					for(int i=0; i<CUBE_SIZE; i++){
						cube[LEFT][i][CUBE_SIZE-1] = line0[i];
						cube[FRONT][0][i] = line1[i];
						cube[RIGHT][i][0] = line2[i];
						cube[BACK][CUBE_SIZE-1][i] = line3[i];
					}	
				}
				rotate_side(UP, clockwise);
				break;
			case 'D':
				if(clockwise){
					for(int i=0; i<CUBE_SIZE; i++){
						line0[i] = cube[LEFT][i][0];
						line1[CUBE_SIZE-i-1] = cube[FRONT][CUBE_SIZE-1][i];
						line2[i] = cube[RIGHT][i][CUBE_SIZE-1];
						line3[CUBE_SIZE-i-1] = cube[BACK][0][i];
					}
					shift(line0, line1, line2, line3);
					for(int i=0; i<CUBE_SIZE; i++){
						cube[LEFT][i][0] = line0[i];
						cube[FRONT][CUBE_SIZE-1][i] = line1[i];
						cube[RIGHT][i][CUBE_SIZE-1] = line2[i];
						cube[BACK][0][i] = line3[i];
					}
				}
				else{
					for(int i=0; i<CUBE_SIZE; i++){
						line0[i] = cube[BACK][0][i];
						line1[CUBE_SIZE-i-1] = cube[RIGHT][i][CUBE_SIZE-1];
						line2[i] = cube[FRONT][CUBE_SIZE-1][i];
						line3[CUBE_SIZE-i-1] = cube[LEFT][i][0];
					}
					shift(line0, line1, line2, line3);
					for(int i=0; i<CUBE_SIZE; i++){
						cube[BACK][0][i] = line0[i];
						cube[RIGHT][i][CUBE_SIZE-1] = line1[i];
						cube[FRONT][CUBE_SIZE-1][i] = line2[i];
						cube[LEFT][i][0] = line3[i];
					}
				}
				rotate_side(DOWN, clockwise);
				break;
			case 'F':
				if(clockwise){
					for(int i=0; i<CUBE_SIZE; i++){
						line0[i] = cube[UP][CUBE_SIZE-1][i];
						line1[CUBE_SIZE-i-1] = cube[RIGHT][CUBE_SIZE-1][i];
						line2[CUBE_SIZE-i-1] = cube[DOWN][0][i];
						line3[i] = cube[LEFT][CUBE_SIZE-1][i];
					}
					shift(line0, line1, line2, line3);
					for(int i=0; i<CUBE_SIZE; i++){
						cube[UP][CUBE_SIZE-1][i] = line0[i];
						cube[RIGHT][CUBE_SIZE-1][i] = line1[i];
						cube[DOWN][0][i] = line2[i];
						cube[LEFT][CUBE_SIZE-1][i] = line3[i];
					}
				}
				else{
					for(int i=0; i<CUBE_SIZE; i++){
						line0[CUBE_SIZE-i-1] = cube[LEFT][CUBE_SIZE-1][i];
						line1[CUBE_SIZE-i-1] = cube[DOWN][0][i];
						line2[i] = cube[RIGHT][CUBE_SIZE-1][i];
						line3[i] = cube[UP][CUBE_SIZE-1][i];
					}
					shift(line0, line1, line2, line3);
					for(int i=0; i<CUBE_SIZE; i++){
						cube[LEFT][CUBE_SIZE-1][i] = line0[i];
						cube[DOWN][0][i] = line1[i];
						cube[RIGHT][CUBE_SIZE-1][i] = line2[i];
						cube[UP][CUBE_SIZE-1][i] = line3[i];
					}
				}
				rotate_side(FRONT, clockwise);
				break;
			case 'B':
				if(clockwise){
					for(int i=0; i<CUBE_SIZE; i++){
						line0[CUBE_SIZE-i-1] = cube[LEFT][0][i];
						line1[CUBE_SIZE-i-1] = cube[DOWN][CUBE_SIZE-1][i];
						line2[i] = cube[RIGHT][0][i];
						line3[i] = cube[UP][0][i];
					}
					shift(line0, line1, line2, line3);
					for(int i=0; i<CUBE_SIZE; i++){
						cube[LEFT][0][i] = line0[i];
						cube[DOWN][CUBE_SIZE-1][i] = line1[i];
						cube[RIGHT][0][i] = line2[i];
						cube[UP][0][i] = line3[i];
					}
				}
				else{
					for(int i=0; i<CUBE_SIZE; i++){
						line0[i] = cube[UP][0][i];
						line1[CUBE_SIZE-i-1] = cube[RIGHT][0][i];
						line2[CUBE_SIZE-i-1] = cube[DOWN][CUBE_SIZE-1][i];
						line3[i] = cube[LEFT][0][i];
					}
					shift(line0, line1, line2, line3);
					for(int i=0; i<CUBE_SIZE; i++){
						cube[UP][0][i] = line0[i];
						cube[RIGHT][0][i] = line1[i];
						cube[DOWN][CUBE_SIZE-1][i] = line2[i];
						cube[LEFT][0][i] = line3[i];
					}
				}
				rotate_side(BACK, clockwise);
				break;
			case 'L':
				if(clockwise){
					for(int i=0; i<CUBE_SIZE; i++){
						line0[i] = cube[BACK][i][0];
						line1[i] = cube[UP][i][0];
						line2[i] = cube[FRONT][i][0];
						line3[i] = cube[DOWN][i][0];
					}
					shift(line0, line1, line2, line3);
					for(int i=0; i<CUBE_SIZE; i++){
						cube[BACK][i][0] = line0[i];
						cube[UP][i][0] = line1[i];
						cube[FRONT][i][0] = line2[i];
						cube[DOWN][i][0] = line3[i];
					}
				}
				else{
					for(int i=0; i<CUBE_SIZE; i++){
						line0[i] = cube[DOWN][i][0];
						line1[i] = cube[FRONT][i][0];
						line2[i] = cube[UP][i][0];
						line3[i] = cube[BACK][i][0];
					}
					shift(line0, line1, line2, line3);
					for(int i=0; i<CUBE_SIZE; i++){
						cube[DOWN][i][0] = line0[i];
						cube[FRONT][i][0] = line1[i];
						cube[UP][i][0] = line2[i];
						cube[BACK][i][0] = line3[i];
					}
				}
				rotate_side(LEFT, clockwise);
				break;
			case 'R':
				if(clockwise){
					for(int i=0; i<CUBE_SIZE; i++){
						line0[i] = cube[DOWN][i][CUBE_SIZE-1];
						line1[i] = cube[FRONT][i][CUBE_SIZE-1];
						line2[i] = cube[UP][i][CUBE_SIZE-1];
						line3[i] = cube[BACK][i][CUBE_SIZE-1];
					}
					shift(line0, line1, line2, line3);
					for(int i=0; i<CUBE_SIZE; i++){
						cube[DOWN][i][CUBE_SIZE-1] = line0[i];
						cube[FRONT][i][CUBE_SIZE-1] = line1[i];
						cube[UP][i][CUBE_SIZE-1] = line2[i];
						cube[BACK][i][CUBE_SIZE-1] = line3[i];
					}
				}
				else{
					for(int i=0; i<CUBE_SIZE; i++){
						line0[i] = cube[BACK][i][CUBE_SIZE-1];
						line1[i] = cube[UP][i][CUBE_SIZE-1];
						line2[i] = cube[FRONT][i][CUBE_SIZE-1];
						line3[i] = cube[DOWN][i][CUBE_SIZE-1];
					}
					shift(line0, line1, line2, line3);
					for(int i=0; i<CUBE_SIZE; i++){
						cube[BACK][i][CUBE_SIZE-1] = line0[i];
						cube[UP][i][CUBE_SIZE-1] = line1[i];
						cube[FRONT][i][CUBE_SIZE-1] = line2[i];
						cube[DOWN][i][CUBE_SIZE-1] = line3[i];
					}
				}
				rotate_side(RIGHT, clockwise);
				break;
		}
	}
	void print_side(int side){
		for(int i=0; i<CUBE_SIZE; i++){
			for(int j=0; j<CUBE_SIZE; j++){
				cout << cube[side][i][j];
			}
			cout << '\n';
		}
	}
private:
	char cube[6][CUBE_SIZE][CUBE_SIZE];

	// line0 -> line1 -> line2 -> line3 -> line0
	void shift(char* line0, char* line1, char* line2, char* line3){
		char tmp;
		for(int i=0; i<CUBE_SIZE; i++){
			tmp = line3[i];
			line3[i] = line2[i];
			line2[i] = line1[i];
			line1[i] = line0[i];
			line0[i] = tmp;
		}
	}
	void rotate_side(int side, bool clockwise=true){
		int tmp;
		if(clockwise){
			tmp = cube[side][0][0];
			cube[side][0][0] = cube[side][CUBE_SIZE-1][0];
			cube[side][CUBE_SIZE-1][0] = cube[side][CUBE_SIZE-1][CUBE_SIZE-1];
			cube[side][CUBE_SIZE-1][CUBE_SIZE-1] = cube[side][0][CUBE_SIZE-1];
			cube[side][0][CUBE_SIZE-1] = tmp;

			tmp = cube[side][0][1];
			cube[side][0][1] = cube[side][1][0];
			cube[side][1][0] = cube[side][CUBE_SIZE-1][1];
			cube[side][CUBE_SIZE-1][1] = cube[side][1][CUBE_SIZE-1];
			cube[side][1][CUBE_SIZE-1] = tmp;
		}
		else{
			tmp = cube[side][0][CUBE_SIZE-1];
			cube[side][0][CUBE_SIZE-1] = cube[side][CUBE_SIZE-1][CUBE_SIZE-1];
			cube[side][CUBE_SIZE-1][CUBE_SIZE-1] = cube[side][CUBE_SIZE-1][0];
			cube[side][CUBE_SIZE-1][0] = cube[side][0][0];
			cube[side][0][0] = tmp;

			tmp = cube[side][1][CUBE_SIZE-1];
			cube[side][1][CUBE_SIZE-1] = cube[side][CUBE_SIZE-1][1];
			cube[side][CUBE_SIZE-1][1] = cube[side][1][0];
			cube[side][1][0] = cube[side][0][1];
			cube[side][0][1] = tmp;

		}
	}
};

int main(){
	int T, n;
	char side, dir;
	cin >> T;
	for(int test_case=0; test_case<T; test_case++){
		Cube my_cube;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> side >> dir;
			if(dir == '+') my_cube.rotate(side);
			else my_cube.rotate(side, false);
		}
		my_cube.print_side(UP);
	}

	return 0;
}
