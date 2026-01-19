class Solution
{
public:
    int solve(int index, int prev_i, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (index < 0)

            return 0;
        if (dp[index][prev_i] != -1)
            return dp[index][prev_i];
        int take = 0;
        int not_take = 0;

        if (prev_i == nums.size() || nums[index] < nums[prev_i])
        {
            take = 1 + solve(index - 1, index, nums, dp);
        }
        not_take = solve(index - 1, prev_i, nums, dp);
        return dp[index][prev_i] = max(take, not_take);
    }
    int lengthOfLIS(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return solve(nums.size() - 1, nums.size(), nums, dp);
    }
};