class Solution
{
public:
    int res = 1;
    int getLength(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int> mp;
            map<int, int> fp;
            for (int j = i; j < nums.size(); j++)
            {
                int before = mp[nums[j]];
                if (before != 0)
                    fp[before]--;
                if (fp[before] == 0)
                {
                    fp.erase(before);
                }

                mp[nums[j]]++;
                if (mp.size() == 1)
                {
                    res = max(res, j - i + 1);
                }
                int after = mp[nums[j]];
                fp[after]++;
                if (fp.size() == 2)
                {
                    int val1 = (*fp.begin()).first;
                    if (fp.find(val1 * 2) != fp.end())
                    {
                        res = max(res, j - i + 1);
                    }
                }
            }
        }
        return res;
    }
};