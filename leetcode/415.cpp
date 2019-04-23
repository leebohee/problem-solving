class Solution {
public:
    void addSumToStr(int sum, bool &carry, string &str){
        if(carry){
            sum++;
        }
            
        if(sum >= 10){
            carry = true;
            sum -= 10; 
        }
        else{
            carry = false;
        }
        str += ((char)(sum + '0'));
    }
    
    string addStrings(string num1, string num2) {
        bool carry = false;
        int idx1 = num1.length() - 1, idx2 = num2.length() - 1;
        int sum;
        string result = "";
        
        while(idx1 >= 0 && idx2 >= 0){
            sum = (num1.at(idx1) - '0') + (num2.at(idx2) - '0');
            addSumToStr(sum, carry, result);
            idx1--;
            idx2--;
        }
        
        while(idx1 >= 0){
            sum = num1.at(idx1) - '0';
            addSumToStr(sum, carry, result);
            idx1--;
        }
        while(idx2 >= 0){
            sum = num2.at(idx2) - '0';
            addSumToStr(sum, carry, result);
            idx2--;
        }
        
        if(carry){
            result += '1';
        }
        reverse(result.begin(), result.end());
        return result;
        
        
    }
};
