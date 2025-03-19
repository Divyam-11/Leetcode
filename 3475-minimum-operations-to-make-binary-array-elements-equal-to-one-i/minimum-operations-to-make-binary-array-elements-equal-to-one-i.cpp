class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] == 0)
            {
                nums[i] = !nums[i];
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];
                result++;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                return -1;
        }
        return result;
    }
};