class Solution
{
public:
    int solve(int i, int j, int charges, vector<vector<int>> &coins, vector<vector<vector<int>>> &dp)
    {
        if (i < 0 || j < 0)
        {
            return INT_MIN;
        }
        if (charges < 0)
            return INT_MIN;
        if (dp[i][j][charges] != -1e9)
        {
            return dp[i][j][charges];
        }
        if (i == 0 && j == 0)
        {
            if (coins[i][j] >= 0)
                return dp[i][j][charges] = coins[i][j];
            if (coins[i][j] < 0)
            {
                if (charges)
                {
                    return dp[i][j][charges] = 0;
                }
                else
                {
                    return dp[i][j][charges] = coins[i][j];
                }
            }
        }
        if (coins[i][j] >= 0)
        {
            int up = solve(i - 1, j, charges, coins, dp);
            int left = solve(i, j - 1, charges, coins, dp);
            if (up == INT_MIN && left == INT_MIN)
            {
                return dp[i][j][charges] = INT_MIN;
            }
            return dp[i][j][charges] = coins[i][j] + max(up, left);
        }
        int use_charge = 0;
        int not_use_charge = 0;
        if (coins[i][j] < 0)
        {
            int up = solve(i - 1, j, charges, coins, dp);
            int left = solve(i, j - 1, charges, coins, dp);
            if (up == INT_MIN && left == INT_MIN)
            {
                not_use_charge = INT_MIN;
            }
            else
            {
                not_use_charge = max(up, left) + coins[i][j];
            }
            up = solve(i - 1, j, charges - 1, coins, dp);
            left = solve(i, j - 1, charges - 1, coins, dp);
            if (up == INT_MIN && left == INT_MIN)
            {
                use_charge = INT_MIN;
            }
            else
            {
                use_charge = max(up, left);
            }
            return dp[i][j][charges] = max(not_use_charge, use_charge);
        }
        return 69;
    }
    int maximumAmount(vector<vector<int>> &coins)
    {
        vector<vector<vector<int>>> dp(coins.size(), vector<vector<int>>(coins[0].size(), vector<int>(3, -1e9)));
        return solve(coins.size() - 1, coins[0].size() - 1, 2, coins, dp);
    }
};