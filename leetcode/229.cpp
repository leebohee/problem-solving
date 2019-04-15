class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int repeat = nums.size() / 3;
        int start = 0, end = 0;
        vector <int> result;
        
        sort(nums.begin(), nums.end());
        while(end < nums.size()){
            if(nums[start] == nums[end]){
                end++;
            }
            else{
                if(end-start > repeat){
                    result.push_back(nums[start]);
                }
                start = end;
            }
        }
        
        if(end-start > repeat){
            result.push_back(nums[start]);
        }
        return result;
    }
};
