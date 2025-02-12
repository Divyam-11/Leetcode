class Solution
{
public:
    int sumOfDigits(int n)
    {
        int sum = 0;
        while (n != 0)
        {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
    int maximumSum(vector<int> &nums)
    {
        int result = -1;
        vector<int> sum_tracker(82, -1);
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = sumOfDigits(nums[i]);
            if (sum_tracker[sum] != -1)
            {
                int index = sum_tracker[sum];
                result = max(result, nums[index] + nums[i]);
                if (nums[i] > nums[index])
                {
                    sum_tracker[sum] = i;
                }
            }
            else
                sum_tracker[sum] = i;
        }
        return result;
    }
};