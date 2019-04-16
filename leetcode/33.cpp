class Solution {
public:
    int search(vector<int>& nums, int target) {
        int cnt = nums.size();
        int left = 0, right = cnt-1, mid;
        
        if(cnt == 0) return -1;
        
        while(left <= right){
            mid = (left+right)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{ // nums[mid] < nums[right]
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
