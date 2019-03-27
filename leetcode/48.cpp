class Solution {
public:
    /***********************************
    1 2 3      7 8 9      7 4 1
    4 5 6  ->  4 5 6  ->  8 5 2
    7 8 9      1 2 3      9 6 3
    ***********************************/
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
