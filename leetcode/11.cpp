class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1, S = 0;
        
        while(i < j){
            S = max(S, (j-i) * min(height[i], height[j]));
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
            
        }
        return S;
    }
};
