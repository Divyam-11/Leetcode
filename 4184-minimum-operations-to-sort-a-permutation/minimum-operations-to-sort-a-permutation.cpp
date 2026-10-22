class Solution
{
public:
    int minOperations(vector<int> &nums)
    {

        int pivot_count = 0;
        int pivot_idx = -1;
        int minus_one = 0;
        int one = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            one = one + (nums[i] - nums[i - 1] == 1);
            minus_one = minus_one + (nums[i] - nums[i - 1] == -1);
            if (abs(nums[i] - nums[i - 1]) != 1)
            {

                pivot_count++;
                pivot_idx = i;
            }
        }
        
        if (pivot_count > 1 || (one !=0 && minus_one!= 0))
            return -1;
        if (pivot_count == 0)
            return nums[0] != 0;
        if (nums[pivot_idx] == 0)
        {
            return min(pivot_idx, (int)(2 + nums.size() - pivot_idx));
        }
        return min(pivot_idx + 1, (int)(1 + nums.size() - pivot_idx));
    }
};