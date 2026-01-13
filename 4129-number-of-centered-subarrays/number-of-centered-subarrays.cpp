class Solution
{
public:
    int centeredSubarrays(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int> mp;
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                mp[nums[j]]++;
                if (mp.find(sum) != mp.end())
                {
                    res++;
                }
            }
        }
        return res;
    }
};