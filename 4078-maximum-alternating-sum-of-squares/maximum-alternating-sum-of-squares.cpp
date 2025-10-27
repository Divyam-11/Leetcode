class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end(), greater<int>());
        long long res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i <= (nums.size() - 1) / 2)
                res += nums[i] * nums[i];
            else
                res -= nums[i] * nums[i];
        }
        return res;
    }
};