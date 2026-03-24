class Solution
{
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> prefix(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>> suffix(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>> p(grid.size(), vector<int>(grid[0].size()));
        long long pre = 1;
        long long post = 1;
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int x = m - i - 1;
                int y = n - j - 1;
                prefix[i][j] = pre;
                suffix[x][y] = post;
                pre = (pre * grid[i][j]) % 12345;
                post = (post * grid[x][y]) % 12345;
            }
        }
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                p[i][j] = (prefix[i][j] * suffix[i][j]) % 12345;
                // cout<<suffix[i][j]<<endl;
            }
        }
        return p;
    }
};