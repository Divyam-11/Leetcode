class Solution
{
public:
    int solve(int index, vector<int> &nums_2, unordered_map<int, int> &mp, vector<int> &dp)
    {
        if (index < 0)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        auto temp = lower_bound(nums_2.begin(), nums_2.begin() + index, nums_2[index] - 1);
        int pick_index = (temp == nums_2.begin()) ? -1 : (int)(temp - nums_2.begin() - 1);

        int pick = (int)nums_2[index] * mp[nums_2[index]] + solve(pick_index, nums_2, mp, dp);
        int not_pick = solve(index - 1, nums_2, mp, dp);
        return dp[index] = max(pick, not_pick);
    }
    int deleteAndEarn(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        vector<int> nums_2;
        for (auto i : mp)
        {
            nums_2.push_back(i.first);
        }
        sort(nums_2.begin(), nums_2.end());
        vector<int> dp(nums_2.size(), -1);
        return solve(nums_2.size() - 1, nums_2, mp, dp);
    }
};