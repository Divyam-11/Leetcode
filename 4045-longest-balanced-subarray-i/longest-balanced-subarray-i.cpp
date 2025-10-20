class Solution
{
public:
    int longestBalanced(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_set<int> even;
            unordered_set<int> odd;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] % 2 == 0)
                {
                    even.insert(nums[j]);
                }
                else
                {
                    odd.insert(nums[j]);
                }
                if (even.size() == odd.size())
                {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};