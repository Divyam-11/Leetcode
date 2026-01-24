class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int l = 0;
        int h = nums.size() - 1;
        int res = 0;
        while (l < h)
        {
            res = max(res, nums[l] + nums[h]);
            l++;
            h--;
        }
        return res;
    }
};