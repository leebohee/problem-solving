class Solution {
public:
    int reverse(int x) {
        vector <int> r;
        int digit = 0, result = 0;
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
            r.push_back(x % 10);
            x = x / 10;
            digit++;
        } while(x != 0);
        
        // reverse x
        digit--;
        for(int i=0; i<=digit; i++){
            result += r[i] * pow(10, (digit-i));
            // check overflow
            if(result < 0) return 0;
        }
        
        return (sign? result : -1*result);
    }
};
