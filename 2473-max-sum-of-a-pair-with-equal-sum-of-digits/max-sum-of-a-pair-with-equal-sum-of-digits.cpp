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
        unordered_map<int, int> sum_tracker; // {sum,index}
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = sumOfDigits(nums[i]);
            if (sum_tracker.find(sum) != sum_tracker.end())
            {
                int index = sum_tracker[sum];
                result = max(result, nums[i] + nums[index]);
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