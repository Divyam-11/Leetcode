class Solution
{
public:
    int MOD = 1e9 + 7;
    int solve(int i, int j, int sum, vector<vector<int>> &grid, int k, vector<vector<vector<int>>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (i == 0 && j == 0)
        {
            sum += grid[0][0] % k;
            if (sum % k == 0)
                return 1;
            return 0;
        }
        if (dp[i][j][sum] != -1)
        {
            return dp[i][j][sum];
        }
        int pick = solve(i - 1, j, (sum + grid[i][j]) % k, grid, k, dp) % MOD;
        int not_pick = solve(i, j - 1, (sum + grid[i][j]) % k, grid, k, dp) % MOD;
        return dp[i][j][sum] = (pick + not_pick) % MOD;
    }

    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k + 1, -1)));
        return solve(grid.size() - 1, grid[0].size() - 1, 0, grid, k, dp);
    }
};