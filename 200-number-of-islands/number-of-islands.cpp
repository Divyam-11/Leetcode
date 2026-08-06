class Solution
{
public:
    vector<int> rows = {-1, 0, 1, 0};
    vector<int> cols = {0, -1, 0, 1};
    void dfs(int x, int y, vector<vector<char>> &grid, int m, int n)
    {
        grid[x][y] = '2';
        for (int i = 0; i < 4; i++)
        {
            int newRow = x + rows[i];
            int newCol = y + cols[i];
            if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n)
            {
                continue;
            }
            if (grid[newRow][newCol] == '1')
            {
                dfs(newRow, newCol, grid, m, n);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid, m, n);
                    count++;
                }
            }
        }
        return count;
    }
};