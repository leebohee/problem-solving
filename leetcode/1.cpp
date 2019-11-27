class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multimap <int, int> us;
        for(int i=0; i<nums.size(); i++){
            us.insert(make_pair(nums[i], i));
        }
        vector <int> result;
        for(int i=0; i<nums.size(); i++){
            int x = target - nums[i];
            if(x == nums[i]){
                auto range = us.equal_range(nums[i]); 
                for(auto itr = range.first; itr != range.second; itr++){
                    result.push_back(itr->second);
                }
                if(result.size() == 2) break;
                result.clear();
            }
            else{
                if(us.find(x) != us.end()){
                    result.push_back(us.find(nums[i])->second);
                    result.push_back(us.find(x)->second);
                    break;
                }
            }
        }
        return result;
    }
};
