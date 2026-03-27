class Solution
{
public:
    long long gcdSum(vector<int> &nums)
    {
        vector<int> prefixGcd(nums.size());
        int mxi = nums[0];
        for (int i = 0; i < prefixGcd.size(); i++)
        {
            mxi = max(mxi, nums[i]);
            prefixGcd[i] = __gcd(mxi, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long res = 0;
        int l = 0;
        int r = prefixGcd.size() - 1;
        while (l < r)
        {
            res += __gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }
        return res;
    }
}

;