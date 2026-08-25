class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for (int i = k; i < 1000; i += k)
        {
            if (mp.find(i) == mp.end())
                return i;

        }
        return INT_MAX;
    }
};