class Solution {
private:
    int func(int index,bool buy,vector<int> & prices,vector<vector<int>> &dp){
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        int profit = 0;
        if(buy){
             profit = max(-prices[index] + func(index+1,false,prices,dp),func(index+1,true,prices,dp));
        }
        else{
            profit = max(prices[index] + func(index+1,true,prices,dp),func(index+1,false,prices,dp));
        }
        dp[index][buy] = profit;
        return profit;  
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return func(0,true,prices,dp);
    }
};