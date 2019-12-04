class Solution {
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
