class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set <char> us;
        int lenJ = J.length(), lenS = S.length(), cnt = 0;
        
        for(int i=0; i<lenJ; i++){
            us.insert(J.at(i));
        }
        
        for(int i=0; i<lenS; i++){
            if(us.find(S.at(i)) != us.end()){
                cnt++;
            }
        }
        
        return cnt;
    }
};
