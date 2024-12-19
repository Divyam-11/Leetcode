class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        vector<int> row = {0, -1, 0, 1};
        vector<int> col = {-1, 0, 1, 0};
        int result = -1;
        queue<pair<int, int>> q;
        int fresh_count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    fresh_count++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                auto temp = q.front();
                q.pop();
                for (int j = 0; j <= 3; j++)
                {
                    int new_row = temp.first + row[j];
                    int new_col = temp.second + col[j];
                    if (new_row < 0 || new_col < 0 || new_row >= grid.size() || new_col >= grid[0].size())
                        continue;
                    if (grid[new_row][new_col] == 1)
                    {
                        grid[new_row][new_col] = 2;
                        fresh_count--;
                        q.push({new_row, new_col});
                    }
                }
            }
            result++;
        }
        if (fresh_count)
            return -1;
        if (result == -1)
            return 0;
        return result;
    }
};