class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int f = 0, f1 = 0, f2 = 0;
        for(int i=2; i<=n; i++){
            f = min(cost[i-1]+f1, cost[i-2]+f2);
            f2 = f1;
            f1 = f;
        }
        
        return f;
    }
};
