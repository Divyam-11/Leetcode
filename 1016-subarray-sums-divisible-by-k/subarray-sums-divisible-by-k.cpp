class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int prefix_sum = 0;
        int result = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            prefix_sum += nums[i];
            int remainder = (prefix_sum % k + k) % k;

            
            result += mp[remainder];

            
            mp[remainder]++;
        }

        return result;
    }
};