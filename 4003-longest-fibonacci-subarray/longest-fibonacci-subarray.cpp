class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int res = 2;
        int cur_len = 2;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] + nums[i - 2])
            {
                cur_len++;
                res = max(cur_len, res);
            }
            else
            {
                cur_len = 2;
            }
        }
        return res;
    }
};