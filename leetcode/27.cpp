class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int r1 = 0, r2 = nums.size()-1;
        while(r1 <= r2){
            if(nums[r1] == val){
                swap(nums[r1], nums[r2]);
                r2--;
            }
            else{
                r1++;
            }
        }
        return r2+1;
    }
};
