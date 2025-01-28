class Solution
{
    vector<int> rows;
    vector<int> columns;
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited, int &cost)
    {
        visited[row][col] = 1;
        cost += grid[row][col];
        for (int i = 0; i < 4; i++)
        {
            int x = row + rows[i];
            int y = col + columns[i];
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
                continue;
            if (grid[x][y] != 0 && !visited[x][y])

            {
                dfs(x, y, grid, visited, cost);
            }
        }
    }

public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        rows = {0, 0, 1, -1};
        columns = {+1, -1, 0, 0};
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (!visited[i][j] && grid[i][j] != 0)
                {
                    int cost = 0;
                    dfs(i, j, grid, visited, cost);
                    result = max(result, cost);
                }
            }
        }
        return result;
    }
};