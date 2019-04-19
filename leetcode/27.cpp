class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int r = 0, w = 0;
        int len = nums.size();
        
        while(r < len){
            if(nums[r] == val){
                r++;
            }
            else{
                nums[w] = nums[r];
                r++;
                w++;
            }
        }
        return w;
    }
};
