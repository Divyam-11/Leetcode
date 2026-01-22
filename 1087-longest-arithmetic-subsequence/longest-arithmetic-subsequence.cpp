class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int res = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(nums.size(), vector<int>(2000 + 1));
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[j] - nums[i] + 1000;
                dp[i][diff] = 1 + dp[j][diff];
                res = max(res, dp[i][diff]);
            }
        }
        return res+1;
    }
};