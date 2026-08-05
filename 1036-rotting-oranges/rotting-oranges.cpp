class Solution
{
public:
    vector<int> rows = {0, -1, 0, 1};
    vector<int> cols = {-1, 0, 1, 0};
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, pair<int, int>>> q;
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2)
                {
                    q.push({0, {i, j}});

                }
            }
        }
        if (fresh == 0)
            return 0;
        while (!q.empty())
        {
            int time = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newRow = x + rows[i];
                int newCol = y + cols[i];
                if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n)
                    continue;
                if (grid[newRow][newCol] == 1)
                {

                    grid[newRow][newCol] = 2;
                    q.push({time + 1, {newRow, newCol}});
                    fresh--;
                    if (fresh == 0)
                    {
                        return time + 1;
                    }
                }
            }
        }

        return -1;
    }
};