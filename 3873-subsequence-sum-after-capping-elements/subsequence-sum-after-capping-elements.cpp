class Solution
{
public:
    vector<bool> subsequenceSumAfterCapping(vector<int> &nums, int k)
    {
        vector<bool> result(nums.size(), false);
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {

                dp[i][j] = dp[i - 1][j];

                if (j >= nums[i - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
        for (int x = 1; x <= nums.size(); x++)
        {
            int t = 0; // num of element  stric less than cap
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] < x)
                    t++;
                else
                    break;
            }
            int num_capped = nums.size() - t;
            for (int j = 0; j < dp[0].size(); j++)
            {
                if (dp[t][j])
                {
                    if (k - j >= 0 && (k - j) % x == 0)
                    {
                        if ((k - j) / x <= num_capped)
                            result[x - 1] = true;
                    }
                }
            }
        }
        return result;
    }
};