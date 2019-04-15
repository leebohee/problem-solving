class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.length() != B.length()){
            return false;
        }
        string new_A = A + A;
        int begin = 0, len = A.length(), end = len-1;
        unordered_set <string> hash_B;
        
        hash_B.insert(B);
        if(hash_B.find(A) != hash_B.end()){
            return true;
        }
        
        while(end < new_A.length()-1){
            auto itr = hash_B.find(new_A.substr(begin, len));
            if(itr != hash_B.end()){ // same string
                return true;
            }
            begin++;
            end++;
        }
        return false;
    }
};
