class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int result = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            result += mp[sum - goal];
            mp[sum]++;
        }
        return result;
    }
};