class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int tmp, limit = matrix.size()/2, N=matrix.size();
        for(int layer=0; layer<limit; layer++){
            for(int i=layer; i<N-(layer+1); i++){
                tmp = matrix[layer][i];
                matrix[layer][i] = matrix[N-1-i][layer];
                matrix[N-1-i][layer] = matrix[N-1-layer][N-1-i];
                matrix[N-1-layer][N-1-i] = matrix[i][N-1-layer];
                matrix[i][N-1-layer] = tmp;
            }    
        }  
    }
};
