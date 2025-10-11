class Solution
{
public:
    long long maximumTotalDamage(vector<int> &power)
    {
        unordered_map<int, int> mp;
        for (int p : power)
            mp[p]++;

        vector<int> nums_2;
        for (auto &it : mp)
            nums_2.push_back(it.first);

        sort(nums_2.begin(), nums_2.end());
        int n = nums_2.size();
        vector<long long> dp(n, 0);

        for (int i = 0; i < n; i++)
        {
            auto it = upper_bound(nums_2.begin(), nums_2.begin() + i, nums_2[i] - 3);
            int prev_index = (it == nums_2.begin()) ? -1 : (int)(it - nums_2.begin()) - 1;

            long long pick = (long long)nums_2[i] * mp[nums_2[i]] + (prev_index >= 0 ? dp[prev_index] : 0);
            long long not_pick = (i > 0 ? dp[i - 1] : 0);

            dp[i] = max(pick, not_pick);
        }

        return dp[n - 1];
    }
};
