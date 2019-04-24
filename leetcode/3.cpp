class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sublen = 0, len = s.length(), start = 0, end = 0;
        unordered_map <char, int> um;
        
        while(end < len){
            auto itr = um.find(s.at(end));
            if(itr != um.end() && start <= (itr->second)){ // repeated character
                sublen = max(sublen, end-start);
                start = (itr->second)+1;
            }
            um[s.at(end)] = end;
            end++;
        }
        
        return max(sublen, end-start);
    }
};
