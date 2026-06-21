class Solution
{
public:
    
    int getLength(vector<int> &nums)
    {   int res = 1;
                unordered_map<int, int> mp;
            unordered_map<int, int> fp;
        for (int i = 0; i < nums.size(); i++)
        {

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
                    int val3 = -1;
                    if(val1 %2 == 0) val3 = val1/2;
                    if (fp.find(val1 * 2) != fp.end() || fp.find(val3) != fp.end())
                    {
                        res = max(res, j - i + 1);
                    }
                }
            }
            mp.clear();
            fp.clear();
        }
        return res;
    }
};