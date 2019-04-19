class Solution {
public:
    bool Compare(string str1, string str2){
        int len1 = str1.length(), len2 = str2.length();
        if(len1 != len2){
            return false;
        }
        for(int i=0; i<len1; i++){
            if(str1.at(i) != str2.at(i)){
                return false;
            }
        }
        return true;
    }
    
    int HashFunc(string str, int start, int len){
        int hash = 0;
        for(int i=0; i<len; i++){
            hash += str.at(start+i);
        }
        return hash;
    }
    
    int strStr(string haystack, string needle) {
        int h_len = haystack.length(), n_len = needle.length();
        
        if(n_len == 0){ // empty string
            return 0;
        }
        if(h_len < n_len){ // (ex) haystack = "aa" needle = "aaaa"
            return -1;
        }
        
        int limit = h_len - n_len;
        int n_hash = HashFunc(needle, 0, n_len);
        int tmp_hash = HashFunc(haystack, 0, n_len);
        for(int i=0; i<limit; i++){
            if(n_hash == tmp_hash){ // same hash value -> compare strings
                if(Compare(haystack.substr(i, n_len), needle)){
                    return i;
                }
            }
            else{
                tmp_hash = tmp_hash - haystack.at(i) + haystack.at(n_len+i);
            }
        }
        return (Compare(haystack.substr(limit, n_len), needle)? limit : -1);
        
    }
};
