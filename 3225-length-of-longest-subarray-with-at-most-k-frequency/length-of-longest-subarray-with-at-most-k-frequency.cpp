class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int maxLen = 1;
        int l = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            while (mp[nums[i]] > k)
            {
                mp[nums[l]]--;
                l++;
            }
            maxLen = max(maxLen, i - l + 1);
        }
        return maxLen;
    }
};