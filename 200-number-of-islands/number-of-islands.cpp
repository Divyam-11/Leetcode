class Solution
{
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &isVisited)
    {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return;
        if (isVisited[row][col] == 1 || grid[row][col] == '0')
            return;
        isVisited[row][col] = 1;
        dfs(row + 1, col, grid, isVisited);
        dfs(row - 1, col, grid, isVisited);
        dfs(row, col + 1, grid, isVisited);
        dfs(row, col - 1, grid, isVisited);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int result = 0;
        vector<vector<int>> isVisited(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    if (!isVisited[i][j])
                    {
                        result++;
                        dfs(i, j, grid, isVisited);
                    }
                }
            }
        }
        return result;
    }
};