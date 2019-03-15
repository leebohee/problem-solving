class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sublen = 0, len = s.length(), start = 0, end = 0;
        unordered_map <char, int> um;
        
        while(end < len){
            auto itr = um.find(s.at(end));
            if(itr != um.end()){ // repeated character
                sublen = max(sublen, end-start);
                start = max((itr->second)+1, start);
            }
            um[s.at(end)] = end;
            end++;
        }
        
        return max(sublen, end-start);
    }
};
