class Solution
{
public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int result = 1;
        int currW = 1;
        int prevW = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                currW++;
                result = max(result,currW/2);
                result = max(result, min(currW, prevW));
            }
            else
            {

                prevW = currW;
                currW = 1;
            }
        }
        return result;
    }
};