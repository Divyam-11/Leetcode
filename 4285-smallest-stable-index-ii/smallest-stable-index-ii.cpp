class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        vector<int> maxScore(nums.size());
        maxScore[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            maxScore[i] = max(maxScore[i - 1], nums[i]);
        }
        int mini = INT_MAX;
        int res = -1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            mini = min(mini, nums[i]);
            if (maxScore[i] - mini <= k)
            {
                res = i;
            }
        }
        return res;
    }
};