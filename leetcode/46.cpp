class Solution {
public:
    void make_permutation(vector<int>& nums, vector<int> perm, bool* mark){
        if(nums.size() == perm.size()){
            permutation.emplace_back(perm);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!mark[i]){
                perm.push_back(nums[i]);
                mark[i] = true;
                make_permutation(nums, perm, mark);
                mark[i] = false;
                perm.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return {};
        bool* mark = new bool [nums.size()];
        for(int i=0; i<nums.size(); i++) mark[i] = false;
        make_permutation(nums, {}, mark);
        delete [] mark;
        return permutation;
    }
private:
    vector<vector<int> > permutation;
};