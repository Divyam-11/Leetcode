class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        vector<long long> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = nums[i] + prefix[i - 1];
        }
        long long total_sum = prefix.back();
        int result = 0;
        for (int i = 0; i < nums.size()-1; i++)
        {
            long long left = prefix[i];
            long long right = total_sum - prefix[i];
            if (left >= right)
            {
                result++;
            }
        }
        return result;
    }
};