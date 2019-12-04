class Solution {
public:
    int mySqrt(int x) {
        int left=1, right=x, mid;
        if(x == 0) return 0;
        while(left <= right){
            mid = (right-left)/2 + left;
            if(mid == x/mid) return mid;
            else if(mid < x/mid) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};
