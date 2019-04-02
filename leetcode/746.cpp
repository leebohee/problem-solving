class Solution {
public:
    int minCostToN(vector<int>& cost, int n, int memo[]){
        if(n == 1){ // on 1st floor
            return 0;
        }
        else if(n == 2){ // 2 steps from 0th floor vs 1 step from 1st floor
            return min(cost[0], cost[1]);
        }
        
        if(!memo[n]){
            memo[n] = min(minCostToN(cost, n-1, memo)+cost[n-1], minCostToN(cost, n-2, memo)+cost[n-2]);
        }
        return memo[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int* memo = new int [n+1];
        memset(memo, 0, (n+1)*sizeof(int));
        return minCostToN(cost, n, memo);
    }
};
