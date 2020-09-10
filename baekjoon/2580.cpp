#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

struct Pos {
	int r;
	int c;
	Pos(int r_, int c_) : r(r_), c(c_) {};
	void print() {
		printf("%d %d\n", r, c);
	}
};

int board[9][9];
vector<Pos> blanks;

void print_board() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}

void fill(int index) {
	if (index == blanks.size()) {
		print_board();
		exit(0);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			bool exist = false;
			// row-wise
			for (int c = 0; c < 9; c++) {
				if (board[blanks[index].r][c] == i) {
					exist = true;
					break;
				}
			}

			// column-wise
			for (int r = 0; r < 9; r++) {
				if (board[r][blanks[index].c] == i) {
					exist = true;
					break;
				}
			}

			// square
			int m = blanks[index].r / 3;
			int n = blanks[index].c / 3;
 			for (int r = 0; r < 3; r++) {
				for (int c = 0; c < 3; c++) {
					if (board[m * 3 + r][n * 3 + c] == i) {
						exist = true;
						break;
					}
				}
				if (exist) break;
			}
			if (exist) {
				continue;
			}
			
			board[blanks[index].r][blanks[index].c] = i;
			fill(index + 1);
			board[blanks[index].r][blanks[index].c] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 0) {
				blanks.emplace_back(i, j);
			}
		}
	}
	fill(0);
	return 0;
}