class Solution {
public:
    int search(vector<int>& nums, int target) {
        int cnt = nums.size();
        int left = 0, right = cnt-1, mid;
        
        while(left <= right){
            mid = (left+right)/2;
            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[left] < nums[right]){ // ordered range
                if(nums[mid] > target){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{ // unordered range
                if(nums[mid] < target){
                    if(nums[left] < nums[mid]){
                        left = mid + 1;
                    }
                    else if(nums[right] < target){
                        right = mid - 1;
                    }
                    else{
                        left = mid + 1;
                    }
                }
                else{
                    if(nums[left] > nums[mid]){
                        right = mid - 1;
                    }
                    else if(nums[left] <= target){
                        right = mid - 1;
                    }
                    else{
                        left = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
};
