class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2,0),cur(2,0);
        dp[0] = dp[1] =0;
        for(int index = n-1;index>=0;index--){
         for(int buy = 0;buy<=1;buy++){
            int profit = 0;
                    if(buy){
             profit = max(-prices[index] + dp[0],dp[1]);
        }
        else{
            profit = max(prices[index] + dp[1],dp[0]);
        }
        cur[buy] = profit;
        }
        dp = cur;
        }
        return dp[1];
    }
};