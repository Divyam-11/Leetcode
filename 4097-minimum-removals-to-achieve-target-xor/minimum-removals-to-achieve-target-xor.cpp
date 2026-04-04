class Solution
{
public:
    int solve(int i, vector<int> &nums, int x, int target, vector<map<int, int>> &dp)
    {
        if (i == nums.size())
        {
            if (x == target)
                return 0;
            else
                return 1e9;
        }
        if (dp[i].find(x) != dp[i].end())
            return dp[i][x];
        int not_pick = 1 + solve(i + 1, nums, x, target, dp);
        int pick = solve(i + 1, nums, x ^ nums[i], target, dp);
        return dp[i][x] = min(pick, not_pick);
    }
    int minRemovals(vector<int> &nums, int target)
    {
        vector<map<int, int>> dp(40);
        int ans = solve(0, nums, 0, target, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};