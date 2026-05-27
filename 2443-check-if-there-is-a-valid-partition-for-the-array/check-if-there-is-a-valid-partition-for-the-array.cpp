class Solution
{
public:
    bool solve(int idx, vector<int> &nums, vector<int> &dp)
    {
        if (idx == nums.size())
            return true;
        if (idx > nums.size())
            return false;
        if (dp[idx] != -1)
            return dp[idx];
        bool res = false;
        if (idx + 1 < nums.size())
        {
            if (nums[idx] == nums[idx + 1])
            {
                res = res || solve(idx + 2, nums, dp);
            }
        }
        if (idx + 2 < nums.size())
        {
            if (nums[idx] == nums[idx + 1] && nums[idx] == nums[idx + 2])
            {
                res = res || solve(idx + 3, nums, dp);
            }
            else if (nums[idx] + 1 == nums[idx + 1] && nums[idx] + 2 == nums[idx + 2])
            {
                res = res || solve(idx + 3, nums, dp);
            }
        }
        return dp[idx] = res;
    }
    bool validPartition(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};