class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int res = nums[0] - nums.back();
        for (int i = 0; i + k - 1< nums.size(); i++)
        {
            res = min(res, nums[i] - nums[i + k - 1]);
        }
        return res;
    }
};