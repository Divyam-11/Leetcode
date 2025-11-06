class Solution
{
public:
    long long lcm(long long a, long long b)
    {
        return (a / __gcd(a, b)) * b;
    }

    long long maxScore(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums.back() * 1LL * nums.back();
        }
        long long all_factor_score = -1;
        long long res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            long long temp_lcm = -1;
            long long temp_gcd = -1;
            for (int j = 0; j < nums.size(); j++)
            {

                if (i == j)
                    continue;
                if (temp_gcd == -1 && temp_lcm == -1)
                {
                    temp_gcd = temp_lcm = nums[j];
                }
                else
                {
                    temp_gcd = __gcd(temp_gcd, (long long)nums[j]);
                    temp_lcm = lcm(temp_lcm, (long long)nums[j]);
                }
            }
            if (all_factor_score == -1)
            {
                all_factor_score = __gcd((long long)nums[i], temp_gcd) * lcm(nums[i], temp_lcm);
                res = max(res, all_factor_score);
            }
            res = max(res, temp_gcd * temp_lcm);
        }
        return res;
    }
};