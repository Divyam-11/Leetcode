class Solution
{
public:
    bool isIncreasing(vector<int> &nums, int idx, int k)
    {   
        if (idx + k > nums.size())
            return false;
        
        for (int i = idx + 1; i < idx + k; i++)
        {
            if (nums[i - 1] >= nums[i])
                return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (isIncreasing(nums, i, k) && isIncreasing(nums, i + k, k))
                return true;
        }
        return false;
    }
};