class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> dict;
        int size = wordDict.size();
        int len = s.length();
        
        for(int i=0; i<size; i++){
            dict.insert(wordDict.at(i));
        }
        
        bool* memo = new bool [len+1];
        memset(memo, false, sizeof(bool)*(len+1));
        memo[0] = true;
        
        string tmp;
        for(int i=1; i<=len; i++){
            for(int j=i-1; j>=0; j--){
                if(memo[j]){
                    tmp = s.substr(j, i-j);
                    if(dict.find(tmp) != dict.end()){
                        memo[i] = true;
                        break;
                    }
                }
            }
        }
        return memo[len];
    }
};
