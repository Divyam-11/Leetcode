class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 != 0)
        {
            return false;
        }
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i][0] = 1;
        }
        if (nums[0] <= target)
            dp[0][nums[0]] = 1;

        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
            {
                int pick = 0;
                if (nums[i] <= j)
                    pick = dp[i - 1][j - nums[i]];
                int not_pick = dp[i - 1][j];
                dp[i][j] = pick || not_pick;
            }
        }
        return dp[nums.size() - 1][target];
    }
};