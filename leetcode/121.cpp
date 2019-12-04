class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        
        int sell = prices[0]; // store minimum price until prices[i]
        int max_profit = 0; // store maximum profit until i-th day
        
        for(int i=1; i<n; i++){
            if(prices[i] < sell) sell = prices[i];
            if(max_profit < prices[i] - sell) max_profit = prices[i] - sell;
        }
        return max_profit;
    }
};
