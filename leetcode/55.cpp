class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        char* memo = new char [size];  // U: not visited, F: cannot reach, T: can reach
        memset(memo, 'U', sizeof(char)*size);
        memo[size-1] = 'T';
        
        for(int i=size-2; i>=0; i--){
            int max_jump = min(size-1, i+nums[i]);
            for(int j=max_jump; j>0; j--){
                if(memo[j] == 'T'){
                    memo[i] = 'T';
                    break;
                }
            }
        }
        return (memo[0] == 'T');
    }
};
