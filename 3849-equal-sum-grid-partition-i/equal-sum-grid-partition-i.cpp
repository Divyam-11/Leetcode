class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        vector<long long> rowPre(grid.size());
        vector<long long> colPre(grid[0].size());
        long long total = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                total += grid[i][j];
                rowPre[i] += grid[i][j];
                colPre[j] += grid[i][j];
            }
        }
        long long sum = 0;
        for (int i = 0; i < rowPre.size(); i++)
        {
            sum += rowPre[i];
            if (total == 2 * sum)
                return true;
        }
        sum = 0;
        for (int i = 0; i < colPre.size(); i++)
        {
            sum += colPre[i];
            if (total == 2 * sum)
                return true;
        }
        return false;
    }
};