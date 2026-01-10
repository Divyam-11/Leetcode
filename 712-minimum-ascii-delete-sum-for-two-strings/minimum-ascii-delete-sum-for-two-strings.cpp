class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[0].size(); j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int run_sum = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            run_sum += s1[i];
        }
        for (int i = 0; i < s2.size(); i++)
        {
            run_sum += s2[i];
        }

        int max_asci = dp.back().back();
        return run_sum - 2 * max_asci;
    }
};