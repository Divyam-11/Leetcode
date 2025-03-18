class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int result = 0;
        int cur = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            while (l < r && (cur & nums[r]) != 0)
            {
                cur ^= nums[l];
                l++;
            }
            
            result = max(result, r - l + 1);
            cur |= nums[r];
        }
        return result;
    }
};