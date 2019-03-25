class Solution {
public:
    vector<int> diStringMatch(string S) {
        int len = S.length(), low = 0, high = len;
        vector <int> A;
        
        for(int i=0; i<len; i++){
            if(S.at(i) == 'I'){
                A.push_back(low++);
            }
            else{
                A.push_back(high--);
            }
        }
        A.push_back(low);
        
        return A;
    }
};
