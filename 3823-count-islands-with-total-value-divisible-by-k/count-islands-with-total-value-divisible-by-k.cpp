class Solution
{
public:
    vector<int> row = {-1, 0, 1, 0};
    vector<int> col = {0, -1, 0, 1};
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, int &total,int k)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] == 1 || grid[i][j] == 0)
            return;
        visited[i][j] = 1;
        total += grid[i][j]%k;
        for (int x = 0; x < 4; x++)
        {
            dfs(i + row[x], j + col[x], grid, visited, total,k);
        }
    }
    int countIslands(vector<vector<int>> &grid, int k)
    {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (visited[i][j] == 0 && grid[i][j] != 0)
                {   
                    cout<<grid[i][j]<<endl;
                    int total = 0;
                    dfs(i, j, grid, visited, total,k);
                    if (total % k == 0)
                        count++;
                }
            }
        }
        return count;
    }
};