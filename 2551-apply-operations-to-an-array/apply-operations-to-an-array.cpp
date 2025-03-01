class Solution
{
public:
    vector<int> applyOperations(vector<int> &nums)
    {
        vector<int> result;
        for (int i = 0; i < nums.size()-1; i++)
        {
            if (nums[i + 1] == nums[i])
            {
                nums[i] *= 2;
                nums[i + 1]=0;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                continue;
            result.push_back(nums[i]);
        }
        while (result.size() != nums.size())
        {
            result.push_back(0);
        }
        return result;
    }
};