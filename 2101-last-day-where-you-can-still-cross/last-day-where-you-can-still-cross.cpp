class Solution
{
public:
    bool floodFill(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        for (int i = 0; i < grid[0].size(); i++)
        {
            if (grid[0][i] == 0)
            {
                q.push({0, i});
                grid[0][i] = 1;
            }
        }
        vector<int> rows = {0, -1, 0, 1};
        vector<int> cols = {-1, 0, 1, 0};
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == grid.size() - 1)
                return true;

            for (int i = 0; i <= 3; i++)
            {
                int new_X = x + rows[i];
                int new_Y = y + cols[i];
                if (new_X < 0 || new_Y < 0 || new_X >= grid.size() || new_Y >= grid[0].size())
                {
                    continue;
                }
                else if (grid[new_X][new_Y] == 0)
                {
                    q.push({new_X, new_Y});
                    grid[new_X][new_Y] = 1;
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int res = 0;

        int low = 0;
        int high = cells.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            vector<vector<int>> grid(row, vector<int>(col, 0));
            for (int i = 0; i <= mid; i++)
            {
                int x = cells[i][0];
                int y = cells[i][1];

                grid[x - 1][y - 1] = 1;
            }
            if (floodFill(grid))
            {
                res = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return res+1;
    }
};