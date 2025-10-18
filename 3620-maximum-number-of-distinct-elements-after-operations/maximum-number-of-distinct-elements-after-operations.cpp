class Solution
{
public:
    int maxDistinctElements(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int count = 1;
        int last = nums[0] - k;

        for (int i = 1; i < nums.size(); i++)
        {
            int next = max(last + 1, nums[i] - k);
            if (next <= nums[i] + k)
            {
                count++;
                last = next;
            }
        }
        return count;
    }
};
