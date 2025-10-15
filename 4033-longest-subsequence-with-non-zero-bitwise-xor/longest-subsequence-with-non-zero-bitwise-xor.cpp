class Solution
{
public:
    int longestSubsequence(vector<int> &nums)
    {
        bool allzero = true;
        int total_xor = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
                allzero = false;
            total_xor ^= nums[i];
        }
        if (total_xor != 0)
            return nums.size();
        else if (total_xor == 0 && allzero)
        {
            return 0;
        }
        else if (total_xor == 0)
            return nums.size() - 1;
        return 0;
    }
};