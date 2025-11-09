class Solution
{
public:
    int maxPathScore(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        int start_cost = grid[0][0] > 0 ? 1 : 0;
        if (start_cost <= k)
            dp[0][0][k - start_cost] = grid[0][0];
        else
            return -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (int rem = k; rem >= 0; rem--)
                {
                    if (dp[i][j][rem] == -1)
                        continue;

                    int cost_down = 0, cost_right = 0;
                    if (i + 1 < n)
                        cost_down = grid[i + 1][j] > 0 ? 1 : 0;
                    if (j + 1 < m)
                        cost_right = grid[i][j + 1] > 0 ? 1 : 0;

                    if (i + 1 < n && rem >= cost_down)
                        dp[i + 1][j][rem - cost_down] = max(dp[i + 1][j][rem - cost_down], dp[i][j][rem] + grid[i + 1][j]);
                    if (j + 1 < m && rem >= cost_right)
                        dp[i][j + 1][rem - cost_right] = max(dp[i][j + 1][rem - cost_right], dp[i][j][rem] + grid[i][j + 1]);
                }
            }
        }

        int ans = -1;
        for (int rem = 0; rem <= k; rem++)
            ans = max(ans, dp[n - 1][m - 1][rem]);
        return ans;
    }
};
