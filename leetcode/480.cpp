class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mset;
        vector<double> result;
        
        for(int i=0; i<k; i++) mset.insert(nums[i]);
        
        int n = nums.size();
        auto mid = next(mset.begin(), k/2);
        for(int i=k; ; i++){
            double median = *mid;
            if(k % 2 == 0){
                median += *prev(mid, 1);
                median /= 2;
            }
            result.push_back(median);
            
            if(i == n) break;
            // insert
            mset.insert(nums[i]);
            if(nums[i] < *mid) mid--;
            
            // erase
            if(nums[i-k] <= *mid) mid++;
            mset.erase(mset.lower_bound(nums[i-k]));
        }
        
        return result;
    }
};
