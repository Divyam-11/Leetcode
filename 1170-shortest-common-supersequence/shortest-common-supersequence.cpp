class Solution
{
public:
    string shortestCommonSupersequence(string text1, string text2)
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
        int i = x - 1;
        int j = y - 1;
        string result;
        while (i > 0 && j > 0)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                result.push_back(text1[i - 1]);
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                result.push_back(text1[i - 1]);
                i--;
            }
            else
            {
                result.push_back(text2[j - 1]);
                j--;
            }
        }
        while (i > 0)
        {
            result.push_back(text1[i - 1]);
            i--;
        }
        while (j > 0)
        {
            result.push_back(text2[j - 1]);
            j--;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};