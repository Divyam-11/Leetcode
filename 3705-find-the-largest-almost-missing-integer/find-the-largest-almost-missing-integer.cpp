class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {
        int maxi = 0;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            maxi = max(maxi, nums[i]);
        }
        if (k == nums.size())
            return maxi;
        if(k == 1){
            int ans = -1;
            for(auto it : mp) {
                if(it.second == 1) ans = max(ans,it.first);
            }
            return ans;
        }
        int res = -1;
        if (mp[nums[0]] == 1)
            res = nums[0];
        if (mp[nums.back()] == 1)
        {
            res = max(res, nums.back());
        }
        return res;
    }
};