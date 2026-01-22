class Solution
{
public:
    int minimumPairRemoval(vector<int> &nums)
    {
        int ops = 0;
        bool flag = false;
        while (flag != true)
        {
            int minSum = INT_MAX;
            int minSumIdx = 0;
            flag = true;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i + 1] < nums[i])
                {
                    flag = false;
                }
                if (nums[i + 1] + nums[i] < minSum)
                {
                    minSum = nums[i + 1] + nums[i];
                    minSumIdx = i;
                }
            }
                        if (flag == true)
                break;
            ops++;
            nums.erase(nums.begin() + minSumIdx + 1);
            nums[minSumIdx] = minSum;
        }
        return ops;
    }
};