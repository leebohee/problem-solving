class Solution {
public:
    int climbStairsWithMemo(int n, int memo[]){
        if(n == 1){
            return 1;
        }
        else if(n == 2){
            return 2;
        }
        else{
            if(!memo[n]){
                memo[n] = climbStairsWithMemo(n-1, memo) + climbStairsWithMemo(n-2, memo);
            }
            return memo[n];
        }
    }
    int climbStairs(int n) {
        int* memo = new int [n+1];
        memset(memo, 0, (n+1)*sizeof(int));
        return climbStairsWithMemo(n, memo);
    }
};
