class Solution
{
public:
    int solve(int index, int m, int n, vector<string> &strs, vector<vector<vector<int>>> &dp)
    {

        if (index < 0)
            return 0;
        
        if (dp[index][m][n] != -1)
            return dp[index][m][n];
        
        int count_0 = 0;
        int count_1 = 0;
        for (int i = 0; i < strs[index].size(); i++)
        {
            if (strs[index][i] == '0')
            {
                count_0++;
            }
            if (strs[index][i] == '1')
            {
                count_1++;
            }
        }

        int pick = 0;
        if (count_0 <= m && count_1 <= n)
        {
            pick = 1 + solve(index - 1, m - count_0, n - count_1, strs, dp);
        }
        int not_pick = solve(index - 1, m, n, strs, dp);
        
        return dp[index][m][n] = max(pick, not_pick);
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(strs.size() - 1, m, n, strs, dp);
    }
};