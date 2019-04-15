class Solution {
public:
    int searchRangeIndex(vector <int> &nums, int left, int right, int target){
        int mid;
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        bool find = false;
        vector <int> range;
        
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] == target){
                find = true;
                break;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        if(!find){
            range.push_back(-1);
            range.push_back(-1);
        }
        else{
            int start = mid, end = mid;
            range.push_back(start);
            range.push_back(end);
            while((start = searchRangeIndex(nums, left, start-1, target)) != -1){
                range[0] = start;
            }
            while((end = searchRangeIndex(nums, end+1, right, target)) != -1){
                range[1] = end;
            }
        }
        return range;
    }
};
