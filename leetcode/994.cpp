class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), minute;
        queue < vector <int> > q;
        vector <int> u, v;
        
        // push initial rotten oranges' information into queue
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 2){
                    v.push_back(i);  // row
                    v.push_back(j);  // column
                    v.push_back(0);  // minute (iteration)
                    q.push(v);
                    v.clear();
                }
            }
        }
        
        // BFS
        while(!q.empty()){
            v = q.front();
            minute = v[2];
            if((v[0] > 0) && grid[v[0]-1][v[1]] == 1){
                grid[v[0]-1][v[1]] = 2;
                u.push_back(v[0]-1);
                u.push_back(v[1]);
                u.push_back(v[2]+1);
                q.push(u);
                u.clear();
            }
            if((v[0] < rows-1) && grid[v[0]+1][v[1]] == 1){
                grid[v[0]+1][v[1]] = 2;
                u.push_back(v[0]+1);
                u.push_back(v[1]);
                u.push_back(v[2]+1);
                q.push(u);
                u.clear();
            }
            if((v[1] > 0) && grid[v[0]][v[1]-1] == 1){
                grid[v[0]][v[1]-1] = 2;
                u.push_back(v[0]);
                u.push_back(v[1]-1);
                u.push_back(v[2]+1);
                q.push(u);
                u.clear();
            }
            if((v[1] < cols-1) && grid[v[0]][v[1]+1] == 1){
                grid[v[0]][v[1]+1] = 2;
                u.push_back(v[0]);
                u.push_back(v[1]+1);
                u.push_back(v[2]+1);
                q.push(u);
                u.clear();
            }
            q.pop();
        }
        
        // check if fresh orange exists
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return minute;
        
    }
};
