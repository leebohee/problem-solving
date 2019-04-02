class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        else if(x == 0){
            return true;
        }
        int N = log10(x)+1, origin = x, reverse = 0;
        bool odd = false;
        if(N % 2 == 1){
            odd = true;
        }
        N = N / 2;
        while(N != 0){
            reverse += (origin%10) * pow(10, --N);
            origin /= 10;
        }
        if(odd){
            origin /= 10;   
        }
        return (origin == reverse)? true : false;
    }
};
