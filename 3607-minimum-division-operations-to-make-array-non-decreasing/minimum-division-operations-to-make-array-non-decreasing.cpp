class Solution
{
public:
    int trial_division2(int n)
    {
        int smallest_factor = -1;
        int factorization = 1;
        while (n % 2 == 0)
        {
            if (smallest_factor == -1)
                smallest_factor = 2;
            factorization *= 2;
            n /= 2;
        }
        for (long long d = 3; d * d <= n; d += 2)
        {
            while (n % d == 0)
            {
                if (smallest_factor == -1)
                    smallest_factor = d;
                factorization *= d;
                n /= d;
            }
        }
        if (n > 1)
        {
            if (smallest_factor == -1)
                smallest_factor = n;
            factorization *= n;
        }
        if (factorization == smallest_factor)
            return -1;
        return factorization / smallest_factor;
    }
    int minOperations(vector<int> &nums)
    {
        int ops = 0;
        int greatest_so_far = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--)

        {
            if (nums[i] > greatest_so_far)
            {
                int get_proper_divisor = trial_division2(nums[i]);
                if (get_proper_divisor == -1)
                    return -1;
                nums[i] /= get_proper_divisor;
                if(nums[i] > greatest_so_far) return -1;
                greatest_so_far = min(greatest_so_far, nums[i]);
                ops++;
                
            }
            greatest_so_far = min(greatest_so_far,nums[i]);
        }
        return ops;
    }
};