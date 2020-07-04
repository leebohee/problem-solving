class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        bool ascend = true;
        int n = A.size();
        if(n < 3) return false;
        for(int i=1; i<n; i++){
            if(ascend && A[i] > A[i-1]) continue;
            else if(i > 1 && ascend && A[i] < A[i-1]) ascend = false;
            else if(!ascend && A[i] < A[i-1]) continue;
            else return false;
        }
        return !ascend;
    }
};