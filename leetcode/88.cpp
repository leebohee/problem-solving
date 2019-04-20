class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r1 = m-1, r2 = n-1, w = m+n-1;
        while(r1 >= 0 && r2 >= 0){
            if(nums1[r1] <= nums2[r2]){
                nums1[w] = nums2[r2];
                r2--;
            }
            else{
                nums1[w] = nums1[r1];
                r1--;
            }
            w--;
        }
        if(r1 == -1){ // copy all elements left in nums2
            while(r2 >= 0){
                nums1[w] = nums2[r2];
                r2--;
                w--;
            }
        }
    }
};
