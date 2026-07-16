class Solution
{
public:
    long long gcdSum(vector<int> &nums)
    {
        vector<int> prefixGcd(nums.size());
        int mx = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            mx = max(mx, nums[i]);
            prefixGcd[i] = __gcd(nums[i], mx);
            
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int low = 0;
        int high = nums.size() - 1;
        long long ans = 0;
        while (low < high)
        {
            ans += __gcd(prefixGcd[low], prefixGcd[high]);
            low++;
            high--;
        }
        return ans;
    }
};