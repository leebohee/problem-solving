class Solution {
public:
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
                        if(left < len - 2 && s.at(left+2) == s.at(right-1)){
                            left++;
                        }
                        else{
                            right--;
                        }
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
