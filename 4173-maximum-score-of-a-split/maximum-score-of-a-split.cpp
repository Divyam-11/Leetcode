class Solution
{
public:
    long long maximumScore(vector<int> &nums)
    {
        vector<int> suffix(nums.size());
        suffix[nums.size() - 1] = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            suffix[i] = min(nums[i + 1], suffix[i + 1]);
        }
        long long prefix_score = 0;
        long long res = INT_MIN;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            prefix_score += nums[i];
            res = max(prefix_score - suffix[i], res);
        }
        return res;
    }
};