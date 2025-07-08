class Solution {
public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<long long>> dp(coins.size() + 1, vector<long long>(amount + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
            {
                int pick = 0;
                int not_pick = 0;
                if (j >= coins[i - 1])

                {
                    pick = dp[i][j - coins[i - 1]];
                }
                not_pick = dp[i - 1][j];
                dp[i][j] = (long long) pick + (long long)not_pick;
            }
        }
        return dp.back().back();
    }
};