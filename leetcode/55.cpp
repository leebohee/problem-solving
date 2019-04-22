class Solution {
public:
    bool canReach(vector <int> &nums, int pos, int memo[]){
        if(pos == nums.size() - 1){
            return true;
        }
        if(memo[pos] == -1){
            int jump_len = nums[pos];
            bool result = false;
            for(int i=1; i<=jump_len; i++){
                result = result | canReach(nums, pos+i, memo);
                if(result){
                    memo[pos] = 1;
                    return true;
                }
            }
            memo[pos] = 0;
        }
        return memo[pos];
    } 
    
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int* memo = new int [size];  // -1: not visited, 0: cannot reach, 1: can reach
        memset(memo, -1, sizeof(int)*size);
        return canReach(nums, 0, memo);
    }
};
