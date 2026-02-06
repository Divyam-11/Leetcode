class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        int res = nums.size();
        sort(nums.begin(), nums.end());
        int r = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (r < nums.size() && (long long)nums[r] <= (long long)k *1LL* nums[i])
            {
                r++;
            }
            res = min(res, (int)nums.size() - (r - i));
        }
        return res;
    }
};