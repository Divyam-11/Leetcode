class Solution
{
public:
    long long minIncrease(vector<int> &nums)
    {
        long long ops = 0;
        if (nums.size() % 2 == 1)
        {
            for (int i = 1; i < nums.size() - 1; i += 2)
            {
                long long temp = max(nums[i + 1], nums[i - 1]) - nums[i] + 1;
                if (temp > 0)
                    ops += temp;
            }
            return ops;
        }
        long long res = LLONG_MAX;
        // cout << "weee" << endl;
        for (int i = 1; i < nums.size() - 1; i += 2)
        {
            long long temp = max(nums[i + 1], nums[i - 1]) - nums[i] + 1;
            if (temp > 0)
                ops += temp;
        }
        res = min(ops, res);
        ops = 0;
        // cout << "weee" << endl;
        for (int i = 2; i < nums.size() - 1; i += 2)
        {
            long long temp = max(nums[i + 1], nums[i - 1]) - nums[i] + 1;
            if (temp > 0)
                ops += temp;
        }
        res = min(ops, res);
        vector<long long> prefix(nums.size());
        vector<long long> suffix(nums.size());
        int sum = 0;
        // cout << "weee" << endl;
        prefix[1] = max(0LL, (long long)max(nums[2], nums[0]) - nums[1] + 1);
        for (int i = 2; i < nums.size() - 1; i++)
        {
            long long temp = max(nums[i + 1], nums[i - 1]) - nums[i] + 1;
            temp = max(temp, 0LL);
            prefix[i] = prefix[i - 2] + temp;
        }
        // cout << "weee" << endl;
        int x = nums.size() - 2;
        suffix[x] = max(0, max(nums[x + 1], nums[x - 1]) - nums[x] + 1);
        // cout << "weee" << endl;
        for (int i = x - 1; i >= 2; i--)
        {
            long long temp = max(nums[i + 1], nums[i - 1]) - nums[i] + 1;
            temp = max(temp, 0LL);
            suffix[i] = suffix[i + 2] + temp;
        }
        // cout << "weee" << endl;
        for (int i = 1; i < nums.size()-2; i+=2)
        {
            long long pre = prefix[i];
            long long suf = 0;
            if (i + 3 < nums.size())
                suf = suffix[i + 3];
            res = min(suf + pre, res);
        }
        // cout << "weee" << endl;
        return res;
    }
};