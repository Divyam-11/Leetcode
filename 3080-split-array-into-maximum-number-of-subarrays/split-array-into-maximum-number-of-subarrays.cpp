class Solution
{
public:
    int maxSubarrays(vector<int> &nums)
    {
        int minScore = ~0;

        for (int i = 0; i < nums.size(); i++)
        {
            minScore &= nums[i];
        }
        int splits = 0;
        int runsum = ~0;
        if (minScore != 0)
            return 1;
        for (int i = 0; i < nums.size(); i++)
        {
            runsum &= nums[i];
            if (runsum == minScore)
            {
                splits++;
                runsum = ~0;
            }
        }
        return splits;
    }
};