class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int x = text1.size() + 1;
        int y = text2.size() + 1;
        vector<vector<int>> dp(x, vector<int>(y, 0));
        for (int i = 1; i < x; i++)
        {
            for (int j = 1; j < y; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[x - 1][y - 1];
    }
};