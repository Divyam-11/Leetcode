class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int result = 0;
        int min_element_idx = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            int diff = nums[i] - nums[min_element_idx];
            result = max(result, diff);
            if (nums[min_element_idx] > nums[i])
            {
                min_element_idx = i;
            }
        }
        return result != 0 ? result : -1;
    }
};