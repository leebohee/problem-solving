class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1, S = 0;
        int tmp_idx;
        
        while(i < j){
            S = max(S, (j-i) * min(height[i], height[j]));
            if(height[i] < height[j]){
            	tmp_idx = i;
            	while(tmp_idx < j && height[i] >= height[tmp_idx]) tmp_idx++;
            	i = tmp_idx;
            }
            else{
            	tmp_idx = j;
            	while(i < tmp_idx && height[j] >= height[tmp_idx]) tmp_idx--;
                j = tmp_idx;
            }
            
        }
        return S;
    }
};
