int StrToInt(string str){
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
            // determine overflow
            if(sign){ // positive
                if(result > INT_MAX / 10){
                    return INT_MAX;
                }	
                else if(result*10 > INT_MAX - (str.at(idx) - '0')){
                    return INT_MAX;
                }
                else{
                    result = result*10 + (str.at(idx) - '0');
                }
            }
            else{ // negative
                if(result < INT_MIN / 10){
                    return INT_MIN;
                }	
                else if(result*10 < INT_MIN + (str.at(idx) - '0')){
                    return INT_MIN;
                }
                else{
                    result = result*10 - (str.at(idx) - '0');
                }
            }
            idx++;
        }      
        return result;
    }
};
	
	
}
