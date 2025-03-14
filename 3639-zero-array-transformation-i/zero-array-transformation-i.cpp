class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> sweep(nums.size() + 1);
        for (int i = 0; i < queries.size(); i++)
        {
            sweep[queries[i][0]]++;
            sweep[queries[i][1] + 1]--;
        }
        int cumsum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cumsum += sweep[i];
            if (nums[i] > cumsum)
                return false;
        }
        return true;
    }
};