class Solution
{
public:
    int ans = 0;
    void helper(int index, vector<int> &nums, int &xor_sum)
    {
        if (index >= nums.size())
        {
            ans += xor_sum;
            return ;
        }
        xor_sum ^= nums[index];
        helper(index + 1, nums, xor_sum);
        xor_sum ^= nums[index];
        helper(index + 1, nums, xor_sum);
    }
    int subsetXORSum(vector<int> &nums)
    {
        int xor_sum = 0;
        helper(0, nums, xor_sum);
        return ans;
    }
};