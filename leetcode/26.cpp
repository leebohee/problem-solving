class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int r = 1, w = 1, size = nums.size();
        
        if(size == 0){
            return 0;
        }
        
        int prev = nums[0];
        while(r < size){
            if(prev != nums[r]){
                prev = nums[r];
                nums[w] = nums[r];
                w++;
            }
            r++;
        }
        return w;
    }
};
