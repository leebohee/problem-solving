class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        int idx = 0;
        
        // remove white spaces
        while(idx < len && str.at(idx) == ' '){
            idx++;
        }

        // sign
        bool sign = true; // true -> positive, false -> negative
        if(idx < len && str.at(idx) == '-'){
            sign = false;
            idx++;
        }
        else if(idx < len && str.at(idx) == '+'){
            idx++;
        }

        if(idx >= len){
            return 0;
        }
        // number
        int result = 0;
        while(idx < len && (str.at(idx) >= '0' && str.at(idx) <= '9')){
        	// check overflow
            if(result > INT_MAX/10 || (result == INT_MAX/10 && str.at(idx) > '7')){
                return INT_MAX;  
            } 
            if(result < INT_MIN/10 || (result == INT_MIN/10 && str.at(idx) > '8')){
                return INT_MIN;  
            }
            
            if(sign){
                result = result*10 + (str.at(idx)-'0');    
            }
            else{
                result = result*10 - (str.at(idx)-'0');    
            }
            idx++;
        }      
        return result;
    }
};
