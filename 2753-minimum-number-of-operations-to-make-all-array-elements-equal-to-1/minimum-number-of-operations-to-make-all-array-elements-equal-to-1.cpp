class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int maxi = 0;
        int count_ones = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                count_ones++;
            maxi = max(nums[i], maxi);
        }
        if (maxi == 1)
            return 0;
        int ops = INT_MAX;
        if (count_ones)
        {
            return nums.size() - count_ones;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int temp_gcd = nums[i];
            if (temp_gcd == 1)
            {
                ops = 0;
                break;
            }
            for (int j = i + 1; j < nums.size(); j++)
            {
                temp_gcd = __gcd(temp_gcd, nums[j]);
                if (temp_gcd == 1)
                {
                    ops = min(ops, j - i);
                }
            }
        }
        if (ops == INT_MAX)
            return -1;
        return ops + nums.size() - 1;
    }
};