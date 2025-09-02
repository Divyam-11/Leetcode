class Solution
{
    int mod = 1e9 + 7;

public:
    int solve(int i, int j, int up, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j][up] != -1)
            return dp[i][j][up];
        if (grid[i][j] == 1)
        {
            if (up)
            {
                return dp[i][j][up] = solve(i, j - 1, 0, grid, dp) % mod;
            }
            else
                return dp[i][j][up] = solve(i - 1, j, 1, grid, dp) % mod;
        }
        int left = solve(i, j - 1, 0, grid, dp) % mod;
        int upp = solve(i - 1, j, 1, grid, dp) % mod;
        return dp[i][j][up] = (left + upp) % mod;
    }
    int uniquePaths(vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(grid.size() + 1, vector<vector<int>>(grid[0].size() + 1, vector<int>(2, -1)));
        return solve(grid.size() - 1, grid[0].size() - 1, 1, grid, dp);
    }
};