class Solution
{
public:
    vector<int> rows = {-1, 0, 1, 0};
    vector<int> cols = {0, -1, 0, 1};
    void dfs(int x, int y, vector<vector<int>> &grid, int value)
    {
        grid[x][y] = value;
        for (int i = 0; i < 4; i++)
        {
            int newRow = x + rows[i];
            int newCol = y + cols[i];
            if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size())
                continue;
            if (grid[newRow][newCol] == 1)
                dfs(newRow, newCol, grid, value);
        }
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        int val = 2;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(i, j, grid, val);
                    val++;
                }
            }
        }
        unordered_map<int, int> area;
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] != 0)
                    area[grid[i][j]]++;
                res = max(res, area[grid[i][j]]);
            }
        }
        area[0] = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    int sum = 1;
                    unordered_map<int,int> temp;
                    for (int a = 0; a < 4; a++)
                    {
                        int newRow = i + rows[a];
                        int newCol = j + cols[a];
                        if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size() || grid[newRow][newCol] == 0)
                            continue;
                        
                        if(temp[grid[newRow][newCol]] == 0)
                        sum += area[grid[newRow][newCol]];
                        temp[grid[newRow][newCol]]++;
                    }
                    res = max(res, sum);
                }
            }
        }
        return res;
    }
};