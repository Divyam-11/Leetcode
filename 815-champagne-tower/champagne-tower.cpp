class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> grid(101, vector<double>(101, 0));
        grid[0][0] = poured;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (grid[i][j] > 1.0)
                {
                    double excess = grid[i][j] - 1.0;
                    grid[i][j] = 1.0;
                    grid[i + 1][j] += excess / 2;
                    grid[i + 1][j + 1] += excess / 2;

                }
            }
        }
        return grid[query_row][query_glass];
    }
};