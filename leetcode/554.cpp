bool cmp(const pair <int, int>& a, const pair <int, int>& b){
    return (a.second < b.second);
}

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map <int, int> um;
        int rows = wall.size(), bricks, len, result;
        
        for(int i=0; i<rows; i++){
            bricks = wall[i].size();
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
        
        if(um.size() == 1){
            return um.find(len)->second;
        }
        else{
            um.erase(um.find(len));
        }
        
        result = rows - (max_element(um.begin(), um.end(), cmp)->second);
        return result;  
    }
};
