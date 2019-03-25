class Solution {
public:
    vector<int> diStringMatch(string S) {
        int len = S.length(), cntD = 0, j;
        vector <int> A;
        bool chk[len+1] = {false};
        
        // Count the number of D
        for(int i=0; i<len; i++){
            if(S.at(i) == 'D') cntD++;
        }
        // Set A[0] as the number of D
        A.push_back(cntD);
        chk[A[0]] = true;
        
        for(int i=0; i<len; i++){
            if(S.at(i) == 'I'){
                j = 1;
                while(chk[A[i]+j]){
                    j++;
                }
                A.push_back(A[i]+j);
            }
            else{
                j = 1;
                while(chk[A[i]-j]){
                    j++;
                }
                A.push_back(A[i]-j);
            }
            chk[A[i+1]] = true;
        }
        
        return A;
    }
};
