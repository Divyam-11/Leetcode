class Solution
{
public:
    vector<int> rows = {-1, 0, 1, 0};
    vector<int> cols = {0, -1, 0, 1};
    void dfs(int x, int y, vector<vector<int>> &grid, int m, int n)
    {
        grid[x][y] = 2;
        for (int i = 0; i < 4; i++)
        {
            int newRow = x + rows[i];
            int newCol = y + cols[i];
            if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n)
            {
                continue;
            }
            if (grid[newRow][newCol] == 1)
                dfs(newRow, newCol, grid, m, n);
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 1)
            {
                dfs(i, 0, grid, m, n);
            }
            if (grid[i][n - 1] == 1)
            {
                dfs(i, n - 1, grid, m, n);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (grid[0][i] == 1)
                dfs(0, i, grid, m, n);
            if (grid[m - 1][i] == 1)
                dfs(m - 1, i, grid, m, n);
        }
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    res++;
            }
        }
        return res;
    }
};