class Solution
{
public:
    vector<vector<int>> dp;

    int solve(int i, int j, int sum, vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        if (i >= m || j >= n)
            return INT_MAX; // impossible path

        if (dp[i][j] != -1)
            return dp[i][j];

        // bottom-right cell
        if (i == m - 1 && j == n - 1)
        {
            return dp[i][j] = max(1, 1 - matrix[i][j]);
        }

        int right = solve(i, j + 1, sum, matrix);
        int down  = solve(i + 1, j, sum, matrix);

        int need_after = min(right, down);

        return dp[i][j] = max(1, need_after - matrix[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        dp.assign(m, vector<int>(n, -1));
        return solve(0, 0, 0, matrix);
    }
};
