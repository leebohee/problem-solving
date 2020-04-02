class Solution {
public:
    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void revert(vector<int>& nums, int idx){
        int n = nums.size();
        int cnt = n - idx;
        for(int i=idx, j=1; j<=cnt/2; i++, j++){
            swap(&nums[i], &nums[n-j]);
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = n-1;
        
        if(n == 1){
            return;
        }
        
        while(idx > 0){
            if(nums[idx] <= nums[idx-1]){
                idx--;
            }
            else{
                break;
            }
        }
        if(idx == n-1){
            swap(&nums[n-2], &nums[n-1]);
            return;
        }
        revert(nums, idx);
        if(idx > 0){
            idx--;
            for(int i=idx+1; i<n; i++){
                if(nums[idx] < nums[i]){
                    swap(&nums[idx], &nums[i]);
                    break;
                }
            }
        } 
        
    }
};
