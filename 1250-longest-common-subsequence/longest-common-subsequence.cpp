class Solution
{
public:
    int solve(int x, int y, string &text1, string &text2, vector<vector<int>> &dp)
    {
        if (x == 0 || y == 0)
            return 0;
        if (dp[x][y] != -1)
            return dp[x][y];
        if (text1[x - 1] == text2[y - 1])
        {
            return dp[x][y] = 1 + solve(x - 1, y - 1, text1, text2, dp);
        }
        else
        {
            int first = solve(x - 1, y, text1, text2, dp);
            int second = solve(x, y - 1, text1, text2, dp);
            return dp[x][y] = max(first, second);
        }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, text1, text2, dp);
    }
};