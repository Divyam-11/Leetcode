class Solution
{
public:
    int partitionArray(vector<int> &nums, int k)
    {
        int result = 1;
        int l = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (abs(nums[i] - nums[l]) > k)
            {
                l = i;
                result++;
            }
        }
        return result;
    }
};