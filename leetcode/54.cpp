class Solution {
public:
    void ReadMatrix(vector < vector <int> >& matrix, int ith, vector <int>& spiral){
        int rows = matrix.size() - 2*ith;
        int cols = matrix[0].size() - 2*ith;
        int j, k;
        
        if(rows <= 0 || cols <= 0){
            return;
        }
        
        if(rows == 1){
            for(int j=ith; j<ith+cols; j++){
                spiral.push_back(matrix[ith][j]);
            }
            return;
        }
        else if(cols == 1){
            for(int j=ith; j<ith+rows; j++){
                spiral.push_back(matrix[j][ith]);
            }
            return;
        }
        else{
            // กๆ
            for(j=ith; j<ith+cols; j++){
                spiral.push_back(matrix[ith][j]);
            }
            // ก้
            for(k=ith+1, j--; k<ith+rows; k++){
                spiral.push_back(matrix[k][j]);
            }
            // ก็
            for(j=j-1, k--; j>=ith; j--){
                spiral.push_back(matrix[k][j]);
            }
            // ก่
            for(k=k-1, j++; k>ith; k--){
                spiral.push_back(matrix[k][j]);
            }

            ReadMatrix(matrix, ith+1, spiral);
        }
        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector <int> spiral;
        
        if(m == 0){ // empty matrix
            return spiral;
        }
        
        ReadMatrix(matrix, 0, spiral);
        
        return spiral;
    }
};
