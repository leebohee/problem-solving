class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        int target;
        vector < vector <int> > result;
        vector <int> tmp_result;
        unordered_multimap <int, int> us;
        
        sort(nums.begin(), nums.end()); // O(NlogN)
        
        for(int i=0; i<size; i++){
            us.insert(make_pair(nums[i], i));
        }
        for(int i=0; i<size; i++){
            for(int j=i+1; j<size; j++){
                target = -1 * (nums[i] + nums[j]);
                auto itr = us.find(target);
                if(itr != us.end() && (itr->second > j)){ // exist
                    tmp_result.push_back(nums[i]);
                    tmp_result.push_back(target);
                    tmp_result.push_back(nums[j]);
                    result.push_back(tmp_result);
                    tmp_result.clear();
                }
                // skip duplicate
                while(j < size-1 && nums[j] == nums[j+1]){
                    j++;
                }
            }
            // skip duplicate
            while(i < size-1 && nums[i] == nums[i+1]){
                i++;
            }
        }
        
        return result;
    }
};
