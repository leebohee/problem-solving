class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap; // (value, index)
        int n = nums.size();
        for(int i=0; i<n; i++){
            auto it = umap.find(target-nums[i]);
            if(it == umap.end()) umap.emplace(nums[i], i);
            else return {it->second, i};
        }
        return {-1, -1};
    }
};
