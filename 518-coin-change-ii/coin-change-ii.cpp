class Solution
{
public:
    int helper(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (amount == 0)
            return 1;
        if (amount < 0 || index < 0)
            return 0;
        if (dp[index][amount] != -1)
        {
            return dp[index][amount];
        }
        int pick = helper(index, amount - coins[index], coins, dp);
        int not_pick = helper(index - 1, amount, coins, dp);
        return dp[index][amount] = pick + not_pick;
    }
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return helper(coins.size() - 1, amount, coins, dp);
    }
};