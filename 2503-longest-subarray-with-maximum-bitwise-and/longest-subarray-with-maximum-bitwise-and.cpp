class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int largest = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            largest = max(nums[i], largest);
        }
        int result = 0;
        int temp = 0;
        for (auto i : nums)
        {
            if (i == largest)
            {
                temp++;
                result = max(result, temp);
            }
            else
                temp = 0;
        }
        return result;
    }
};