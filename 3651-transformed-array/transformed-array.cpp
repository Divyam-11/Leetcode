class Solution
{
public:
    vector<int> constructTransformedArray(vector<int> &nums)
    {
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                int idx = (i + nums[i]) % (int)nums.size();
                result[i] = nums[idx];
            }
            else if (nums[i] < 0)
            {
                int idx = ((i + nums[i]) % (int)nums.size() + (int)nums.size()) % (int)nums.size();
                result[i] = nums[idx];
            }
            else
            {
                result[i] = nums[i];
            }
        }
        return result;
    }
};