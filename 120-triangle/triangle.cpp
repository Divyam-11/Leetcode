class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(),INT_MAX));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                int mincost = dp[i - 1][j];
                if (j - 1 >= 0)
                    mincost = min(dp[i - 1][j], dp[i - 1][j - 1]);
                mincost += triangle[i][j];
            dp[i][j] = mincost;
            }
        }
        int ans = INT_MAX;
        for(auto i : dp.back()){
            ans = min(ans,i);
        }
        return ans;
    }
};