class Solution {
public:
    bool isPalindrome(string s, int left, int right){
        while(left <= right){
            if(s.at(left) == s.at(right)){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        bool deleted = false;
        int len = s.length(), left = 0, right = len - 1;
        
        while(left <= right){
            if(s.at(left) == s.at(right)){
                left++;
                right--;
            }
            else{
                if(!deleted){
                    deleted = true;
                    if(s.at(left+1) == s.at(right) && s.at(left) == s.at(right-1)){
                        bool result = isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
                        return result;
                    }
                    else if(s.at(left+1) == s.at(right)){
                        left++;
                    }
                    else if(s.at(left) == s.at(right-1)){
                        right--;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
