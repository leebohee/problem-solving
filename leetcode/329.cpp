class Solution {
public:
    int FindPath(vector<vector<int>>& matrix, int r, int c, int** memo){
        int len = 1;
        
        // (r-1, c)
        if((r > 0) && (matrix[r-1][c] > matrix[r][c])){ 
            if(memo[r-1][c] > 0){
                len = max(len, memo[r-1][c]+1);
            }
            else{
                len = max(len, FindPath(matrix, r-1, c, memo)+1);       
            }
        }
        // (r+1, c)
        if((r < matrix.size()-1) && (matrix[r+1][c] > matrix[r][c])){ 
            if(memo[r+1][c] > 0){
                len = max(len, memo[r+1][c]+1);
            }
            else{
                len = max(len, FindPath(matrix, r+1, c, memo)+1);       
            }
        }
        // (r, c-1)
        if((c > 0) && (matrix[r][c-1] > matrix[r][c])){ 
            if(memo[r][c-1] > 0){
                len = max(len, memo[r][c-1]+1);
            }
            else{
                len = max(len, FindPath(matrix, r, c-1, memo)+1);       
            }
        }
        // (r, c+1)
        if((c < matrix[0].size()-1) && (matrix[r][c+1] > matrix[r][c])){ 
            if(memo[r][c+1] > 0){
                len = max(len, memo[r][c+1]+1);
            }
            else{
                len = max(len, FindPath(matrix, r, c+1, memo)+1);       
            }
        }
        
        memo[r][c] = len;
        return len;
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(rows == 0) return 0;
        int cols = matrix[0].size(), len = 0;
        int** memo = new int* [rows];
        for(int i=0; i<rows; i++){
            memo[i] = new int [cols];
            for(int j=0; j<cols; j++){
                memo[i][j] = 0;
            }
        }
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(memo[i][j] == 0){ // find length of longest path from (i, j)
                    memo[i][j] = FindPath(matrix, i, j, memo);
                }
                len = max(len, memo[i][j]);
            }
        }
        return len;
    }
};
