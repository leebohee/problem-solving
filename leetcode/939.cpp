class Solution {
public:
	#define MAX 40001
    int minAreaRect(vector<vector<int>>& points) {
    	unordered_set<int> points_1d;
    	for(const auto& p: points){
    		points_1d.insert(p[0]*MAX + p[1]);
    	}
        
        int n = points.size();
        int min_area = INT_MAX;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
            	if(points[i][0] == points[j][0]) continue;
            	if(points[i][1] == points[j][1]) continue;
            	if(points_1d.find(points[i][0]*MAX + points[j][1]) != points_1d.end()){
            		if(points_1d.find(points[j][0]*MAX + points[i][1]) != points_1d.end()){
            			int width = abs(points[i][0] - points[j][0]);
            			int height = abs(points[i][1] - points[j][1]);
            			min_area = min(min_area, height*width);
            		}
            	}
            }
        }
        return min_area == INT_MAX ? 0 : min_area;
    }
};