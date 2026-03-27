class Solution
{
public:
    void shift(int i, vector<vector<int>> &grid, int k)
    {
        if (i % 2 == 0)
        {
            k *= -1;
        }
        vector<int> temp(grid[0].size());
        for (int j = 0; j < grid[0].size(); j++)
        {
            int idx = ((j + k + grid[0].size()) % (int)grid[0].size());
            temp[idx] = grid[i][j];
        }
        grid[i] = temp;
    }

    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        vector<vector<int>> grid = mat;
        for (int i = 0; i < mat.size(); i++)
        {   
            int tempk = k;
            while(tempk--)
            shift(i, grid, 1);
        }
        return grid == mat;
    }
};