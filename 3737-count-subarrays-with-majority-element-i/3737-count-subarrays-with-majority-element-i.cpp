class Solution
{
public:
    int countMajoritySubarrays(vector<int> &nums, int target)
    {
        int res = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int> mp;
            for (int j = i; j < nums.size(); j++)
            {
                mp[nums[j]]++;
                if (mp[target] > (j - i + 1) / 2)
                    res++;
            }
        }
        return res;
    }
};