class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int lastPossible = size - 1;
        
        for(int i=size-2; i>=0; i--){
            if(i+nums[i] >= lastPossible){
                lastPossible = i;
            }
        }
        return (lastPossible == 0);
    }
};
