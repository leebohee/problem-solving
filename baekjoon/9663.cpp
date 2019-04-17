#include <cstring>
#include <iostream>

using namespace std;

class NQueen{
	private:
		int N;
		int cases;
		int* queens; // index -> row, value -> column
		
		bool IsPossible(int r, int c){
			for(int i=0; i<r; i++){
				// a queen exists at the same vertical line
				if(queens[i] == c){ 
					return false;
				}
				// a queen exists at the same cross line
				if(queens[i] == c-(r-i) || queens[i] == c+(r-i)){
					return false;
				}
			}
			return true;
		}
		void DFS(int r, int c){
			if(r == N-1){ // end
				cases++;
			}
			for(int i=0; i<N; i++){
				if(IsPossible(r+1, i)){
					queens[r+1] = i;
					DFS(r+1, i);
				}
			}
		}
	public:
		NQueen(int _N){
			N = _N;
			cases = 0;
			queens = new int [N];
			memset(queens, -1, sizeof(int)*N);
		}
		
		
		int Cases(void){
			for(int i=0; i<N; i++){
				queens[0] = i;
				DFS(0, i);
			}
			return cases;
		}
		~NQueen(){
			delete [] queens;
		}
};


int main(){
	int N;
	cin >> N;
	
	NQueen n_queen(N);
	cout << n_queen.Cases();
	return 0;
}
