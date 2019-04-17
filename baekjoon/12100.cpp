#include <iostream>
#include <vector>

using namespace std;

vector < vector <int> > Move(vector < vector <int> > board, int dir){
	int N = board.size(), pos, r, c;
	
	if(dir == 0){ // up
		for(c=0; c<N; c++){
			pos = 0;
			r = 0;
			while(r < N && board[r][c] == 0){
				r++;
			}
			while(r < N){
				if(board[r][c] == 0){
					r++;
				}
				int next = r+1;
				while(next < N && board[next][c] == 0){
					next++;
				}
				if(next < N && board[r][c] == board[next][c]){
					board[pos][c] = 2*board[r][c];
					r = next + 1;
					pos++;
				}
				else{
					board[pos][c] = board[r][c];
					r++;
					pos++;
				}
			}
			for(int r=pos; r<N; r++){
				board[r][c] = 0;
			}
		}
	}
	else if(dir == 1){ // left
		for(r=0; r<N; r++){
			pos = 0;
			c = 0;
			while(c < N && board[r][c] == 0){
				c++;
			}
			while(c < N){
				if(board[r][c] == 0){
					c++;
				}
				int next = c+1;
				while(next < N && board[r][next] == 0){
					next++;
				}
				if(next < N && board[r][c] == board[r][next]){
					board[r][pos] = 2*board[r][c];
					c = next + 1;
					pos++;
				}
				else{
					board[r][pos] = board[r][c];
					c++;
					pos++;
				}
			}
			for(int c=pos; c<N; c++){
				board[r][c] = 0;
			}
		}
	}
	else if(dir == 2){ // right
		for(int r=0; r<N; r++){
			pos = N-1;
			c = N-1;
			while(c >= 0 && board[r][c] == 0){
				c--;
			}
			while(c >= 0){
				if(board[r][c] == 0){
					c--;
				}
				int next = c-1;
				while(next < N && board[r][next] == 0){
					next--;
				}
				if(next >= 0 && board[r][c] == board[r][next]){
					board[r][pos] = 2*board[r][c];
					c = next - 1;
					pos--;
				}
				else{
					board[r][pos] = board[r][c];
					c--;
					pos--;
				}
			}
			for(int c=pos; c>=0; c--){
				board[r][c] = 0;
			}
		}
	}
	else{ // down
		for(int c=0; c<N; c++){
			pos = N-1;
			r = N-1;
			while(r >= 0 && board[r][c] == 0){
				r--;
			}
			while(r >= 0){
				if(board[r][c] == 0){
					r--;
				}
				int next = r-1;
				while(next >= 0 && board[next][c] == 0){
					next--;
				}
				if(next >= 0 && board[r][c] == board[next][c]){
					board[pos][c] = 2*board[r][c];
					r = next - 1;
					pos--;
				}
				else{
					board[pos][c] = board[r][c];
					r--;
					pos--;
				}
				
			}
			for(int r=pos; r>=0; r--){
				board[r][c] = 0;
			}
		}
	}
	return board;
}

int MaxBlock(vector < vector <int> > board, int ith){
	int max_value = 0, N = board.size();
	
	if(ith == 5){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				max_value = max(max_value, board[i][j]);
			}
		}
		return max_value;
	}

	for(int i=0; i<4; i++){
		vector < vector <int> > new_board = Move(board, i);	
		
		for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << new_board[i][j] << ' ';
		}
		cout << endl;
	}
		max_value = max(max_value, MaxBlock(new_board, ith+1));
	}
	return max_value;
	
	/*
*/
}

int main(){
	int N, x;
	vector < vector <int> > board;
	vector <int> v;
	
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> x;
			v.push_back(x);
		}
		board.push_back(v);
		v.clear();
	}
	
	cout << MaxBlock(board, 0);
	
	return 0;
}
