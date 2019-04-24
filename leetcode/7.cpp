class Solution {
public:
    int reverse(int x) {
        int r;
        int result = 0;

        // find the number of digits
        do {
            r = x % 10;
            x = x / 10;
            
            if((result > INT_MAX/10) || (result == INT_MAX/10 && r > 7)) return 0; 
			if((result < INT_MIN/10) || (result == INT_MIN/10 && r < -8)) return 0; 
			       
            result = result*10 + r;
        } while(x != 0);
        
        return result;
    }
};
