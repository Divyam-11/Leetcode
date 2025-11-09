class Solution
{
public:
    int solve(int i, int j, int k, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {   if(k < 0 ) return -1;
        if (i == 0 && j == 0)
        {
            return 0;
        }
        if (i < 0 || j < 0)
        {
            return -1;
        }
        if (dp[i][j][k] != INT_MIN)
            return dp[i][j][k];
        int cost = grid[i][j] > 0 ? 1 : 0;
        if (cost <= k)
        {
            int up = solve(i - 1, j, k-cost, grid, dp);
            int left = solve(i, j - 1, k-cost, grid, dp);
            if (up == -1 && left == -1)
            {
                return dp[i][j][k] = -1;
            }
            if (up == -1)
            {
                up = INT_MIN;
            }
            if (left == -1)
            {
                left = INT_MIN;
            }
            return dp[i][j][k] = grid[i][j] + max(up, left);
        }
        return dp[i][j][k] = -1;
    }
    int maxPathScore(vector<vector<int>> &grid, int k)
    {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k + 1, INT_MIN)));
        int ans = solve(grid.size() - 1, grid[0].size() - 1, k, grid, dp);
        if (ans < 0)
            return -1;
        return ans;
    }
};