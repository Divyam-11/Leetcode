class Solution
{
    int MOD = 1e9 + 7;
    int dp[300][300][16];
    int helper(int i, int j, vector<vector<int>> &grid, int k, int &m, int &n, int total_xor)
    {
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1)
        {
            if (k == (total_xor ^ grid[i][j]))
            {
                return 1;
            }
            return 0;
        }

        total_xor = total_xor ^ grid[i][j];
        if (dp[i][j][total_xor] != -1)
            return dp[i][j][total_xor];
        int result = (helper(i, j + 1, grid, k, m, n, total_xor) % MOD +
                      helper(i + 1, j, grid, k, m, n, total_xor) % MOD) %
                     MOD;

        return dp[i][j][total_xor] = result;
    }

public:
    int countPathsWithXorValue(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp, -1, sizeof dp);
        return helper(0, 0, grid, k, m, n, 0);
    }
};