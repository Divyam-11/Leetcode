class Solution
{
public:
    int climbStairs(int n, vector<int> &costs)
    {
        vector<int> dp(costs.size()+1);

        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++)
        {
            int res = INT_MAX;
            if (i - 1 >= 0)
            {
                res = min(res, dp[i - 1] + costs[i-1] + 1 * 1);
            }
            if (i - 2 >= 0)
            {
                res = min(res, dp[i - 2] + costs[i-1] + 4);
            }
            if (i - 3 >= 0)
            {
                res = min(res, dp[i - 3] + costs[i-1] + 9);
            }
            dp[i] = res;
        }
        return dp.back();
    }
};