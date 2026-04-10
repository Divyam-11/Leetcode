class Solution
{
public:
    long long minIncrease(vector<int> &nums)
    {
        long long ops = 0;
        int n = nums.size();

        if (n % 2 == 1)
        {
            for (int i = 1; i < n - 1; i += 2)
            {
                long long temp = max(nums[i + 1], nums[i - 1]) - nums[i] + 1;
                if (temp > 0)
                    ops += temp;
            }
            return ops;
        }

        long long res = LLONG_MAX;

        for (int i = 1; i < n - 1; i += 2)
        {
            long long temp = max(nums[i + 1], nums[i - 1]) - nums[i] + 1;
            if (temp > 0)
                ops += temp;
        }
        res = min(ops, res);

        ops = 0;

        for (int i = 2; i < n - 1; i += 2)
        {
            long long temp = max(nums[i + 1], nums[i - 1]) - nums[i] + 1;
            if (temp > 0)
                ops += temp;
        }
        res = min(ops, res);

        vector<long long> prefix(n, 0);
        vector<long long> suffix(n, 0);

        prefix[1] = max(0LL, (long long)max(nums[2], nums[0]) - nums[1] + 1);
        for (int i = 2; i < n - 1; i++)
        {
            long long temp = max(nums[i + 1], nums[i - 1]) - nums[i] + 1;
            temp = max(temp, 0LL);
            prefix[i] = prefix[i - 2] + temp;
        }

        int x = n - 2;
        suffix[x] = max(0LL, (long long)max(nums[x + 1], nums[x - 1]) - nums[x] + 1);

        for (int i = x - 1; i >= 2; i--)
        {
            long long temp = max(nums[i + 1], nums[i - 1]) - nums[i] + 1;
            temp = max(temp, 0LL);
            suffix[i] = suffix[i + 2] + temp;
        }

        for (int i = 1; i < n - 2; i += 2)
        {
            long long pre = prefix[i];
            long long suf = 0;
            if (i + 3 < n)
                suf = suffix[i + 3];
            res = min(suf + pre, res);
        }

        return res;
    }
};