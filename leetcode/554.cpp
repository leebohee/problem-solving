bool cmp(const pair <int, int>& a, const pair <int, int>& b){
    return (a.second < b.second);
}

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map <int, int> um;
        int rows = wall.size(), bricks, len, result;
        
        for(int i=0; i<rows; i++){
            bricks = wall[i].size() - 1;
            len = 0;
            for(int j=0; j<bricks; j++){
                len += wall[i][j];
                if(um.find(len) == um.end()){ // not exist
                    um.insert(make_pair(len, 1));
                }
                else{ // exist
                    um[len]++;
                }
            }
        }
        
        result = 0;
        for(auto itr=um.begin(); itr!=um.end(); itr++){
            result = max(itr->second, result);
        }
        
        return rows-result;  
    }
};
