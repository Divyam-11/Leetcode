class Solution
{
public:
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        vector< long long> mp(k+1,1e10);
        mp[0] = 0;
        long long res = -200000000000001;
        long long cur_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {   
        
            cur_sum += nums[i];
            int can_rem = (i + 1) % k;
            if(mp[can_rem] != 1e10)
            res = max(cur_sum - mp[can_rem], res);
            mp[(i + 1) % k] = min(mp[(i + 1) % k], cur_sum);
        }
        return res;
    }
};