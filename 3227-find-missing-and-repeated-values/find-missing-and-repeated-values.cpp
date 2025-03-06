class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        vector<int> freq(grid.size() * grid.size() + 1);
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                freq[grid[i][j]]++;
            }
        }
        vector<int> result(2);
        for (int i = 1; i < freq.size(); i++)
        {
            if (freq[i] == 0)
            {
                result[1] = i;
            }
            if (freq[i] == 2)
            {
                result[0] = i;
            }
        }
        return result;
    }
};