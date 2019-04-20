class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int sizeA = A.size(), sizeB = B.size();
        int idxA = 0, idxB = 0;
        int start, end;
        vector < vector <int> > result;
        
        while(idxA < sizeA && idxB <sizeB){
            start = max(A[idxA][0], B[idxB][0]);
            end = min(A[idxA][1], B[idxB][1]);
            if(start <= end){ // overlap
                result.push_back({start, end});
            }
            
            // increment index of vector that has smaller end point
            if(A[idxA][1] < B[idxB][1]){
                idxA++;
            }
            else{
                idxB++;
            }
        }
        
        return result;
    }
};
