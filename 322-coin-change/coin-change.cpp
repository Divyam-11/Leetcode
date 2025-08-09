class Solution {
private:
int solve(vector<int> &coins,int target,int index,vector<vector<int>> &dp){
if(target == 0){
    return 0;
}
if(index < 0){
    return INT_MAX;
}
if(dp[target][index] != -1){
    return dp[target][index];
}

int take = INT_MAX;
if(target >= coins[index] && solve(coins,target - coins[index],index,dp) != INT_MAX){
    take = 1 + solve(coins,target-coins[index],index,dp);
}
int not_take = solve(coins,target,index-1,dp);
dp[target][index] = min(not_take,take);
return dp[target][index];



}
// pick answer 
// dont pick
// return minimum

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size()+1,-1));
        int result =  solve(coins,amount,coins.size( ) - 1,dp);
        return result == INT_MAX ? -1 : result;
    }
};