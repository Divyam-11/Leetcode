class Solution
{
public:
    int destroyTargets(vector<int> &nums, int space)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        unordered_map<int, int> first;
        int maxRem = 0;
        int maxfreq = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int rem = nums[i] % space;
            if (mp.find(rem) == mp.end())
            {
                mp[rem]++;
                first[rem] = nums[i];
            }
            else
                mp[rem]++;
            if (maxfreq <= mp[rem])
            {
                if (maxfreq == mp[rem] && first[rem] < first[maxRem])
                {
                    maxRem = rem;
                }
                else if (maxfreq < mp[rem])
                {
                    maxfreq = mp[rem];
                    maxRem = rem;
                }
            }
        }
        return first[maxRem];
    }
};