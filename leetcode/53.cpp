class Solution_DP {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), max;
        int memo[n] = {0, };
        max = memo[0] = nums[0];
        
        for(int i=1; i<n; i++){
            memo[i] = nums[i];
            if(memo[i-1] > 0) memo[i] += memo[i-1];
            if(max < memo[i]) max = memo[i];
        }
        return max;
    }
};

class Solution_D {
public:
    struct ret{
        int lsum;
        int rsum;
        int subsum;
        int totalsum;
        ret(int l, int r, int s, int t): lsum(l), rsum(r), subsum(s), totalsum(t) {};
    };
    ret max_subarray(vector<int>& nums, int start, int end){
        if(start == end) return ret(nums[start], nums[start], nums[start], nums[start]);
        int mid = start + (end - start) / 2;
        ret left = max_subarray(nums, start, mid);
        ret right = max_subarray(nums, mid+1, end);
        
        int l = max(left.lsum, left.totalsum + right.lsum);
        int r = max(right.rsum, right.totalsum + left.rsum);
        int s = max(max(left.subsum, right.subsum), left.rsum + right.lsum);
        int t = left.totalsum + right.totalsum;
        
        return ret(l, r, s, t);
    }
    int maxSubArray(vector<int>& nums) {
        return max_subarray(nums, 0, nums.size()-1).subsum;
    }
};
