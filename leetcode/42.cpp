class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 1) return 0;
        
        
        int volume, total_volume = 0;
        int left_max[n];
        int right_max[n];

        left_max[0] = height[0];
        for(int i=1; i<n; i++) left_max[i] = max(left_max[i-1], height[i]);
        
     	right_max[n-1] = height[n-1];
     	for(int i=n-2; i>=0; i--) right_max[i] = max(right_max[i+1], height[i]);
        
        for(int i=1; i<n-1; i++) total_volume += (min(left_max[i], right_max[i]) - height[i]);
        
        return total_volume;
    }
};
