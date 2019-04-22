class Solution {
public:
    bool isAlphanumeric(char ch){
        if(ch >= '0' && ch <= '9'){ // numeric
            return true;
        }
        else if(ch >= 'A' && ch <= 'Z'){ // alphabetic (upper case)
            return true;
        }
        else if(ch >= 'a' && ch <= 'z'){ // alphabetic (lower case)
            return true;
        }
        else{
            return false;
        }
    }
    
    char toUpperCase(char ch){
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - ('a'-'A');
        }
        return ch;
    }
    
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        int len = s.length();
        
        while(left <= right){
            while((left < len) && !isAlphanumeric(s.at(left))){
                left++;
            }
            if(left >= len){
                return true;
            }
            while((right >= 0) && !isAlphanumeric(s.at(right))){
                right--;
            }
            
            if(toUpperCase(s.at(left)) == toUpperCase(s.at(right))){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
