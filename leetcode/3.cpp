class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sublen = 0, len = s.length(), start = 0, end = 0;
        unordered_set <char> us;
        
        while(end < len){
            if(us.find(s.at(end)) != us.end()){ // repeated character
                if(sublen < us.size()){
                    sublen = us.size();
                }
                while(s.at(start) != s.at(end)){
                    us.erase(s.at(start++));
                }
                start++;
            }
            else{
                us.insert(s.at(end));
            }
            end++;
        }
        
        return (sublen > us.size())? sublen : us.size();
    }
};
