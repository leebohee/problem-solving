class Solution {
public:
    int reverse(int x) {
        int r;
        int result = 0;
        bool sign = true;
        
        if(x < 0){
            if(x == INT_MIN) return 0;
            sign = false;
            x = x * -1;
        }
        else if(x == 0){
            return 0;
        }
        
        // find the number of digits
        do {
            r = x % 10;
            x = x / 10;
            
            if((result > INT_MAX/10) || (result == INT_MAX/10 && r > 7)) return 0;        
            result = result*10 + r;
        } while(x != 0);
        
        return (sign? result : -1*result);
    }
};
