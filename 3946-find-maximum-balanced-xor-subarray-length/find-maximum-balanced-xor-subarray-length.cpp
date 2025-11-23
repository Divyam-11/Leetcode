class Solution
{
public:
    int maxBalancedSubarray(vector<int> &nums)
    {
        int res = 0;
        map<pair<int, int>, int> mp;
        mp[{0, 0}] = -1;
        int xr = 0;
        int eo = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                eo++;
            }
            else
            {
                eo--;
            }
            xr = xr ^ nums[i];
            if (mp.find({xr, eo}) != mp.end())
            {
                res = max(res, i - mp[{xr, eo}]);
            }
            else
            {
                mp[{xr, eo}] = i;
            }
        }
        return res;
    }
};