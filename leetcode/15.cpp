class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        // sort nums
        sort(nums.begin(), nums.end());

        vector < vector <int> > result;
        vector <int> triplet;
        for(int k=0; k<n; ){
        	int target = nums[k];
        	int i = k+1, j = n-1;
        	while(i < j){
        		int sum = nums[i] + nums[j];
        		if(-1*target < sum){
        			j--;
        		}
        		else if(-1*target > sum){
        			i++;
        		}
        		else{
		        	triplet.push_back(nums[i]);
		        	triplet.push_back(nums[j]);
		        	triplet.push_back(-1*sum);
		        	result.push_back(triplet);
		        	triplet.clear();
	        		int a = nums[i], b = nums[j];
	        		while(i < j && nums[i] == a) i++;        	
	        		while(i < j && nums[j] == b) j--;
        		}
        	}
        	while(k < n && nums[k] == target) k++;
        }
        return result;
    }
};
