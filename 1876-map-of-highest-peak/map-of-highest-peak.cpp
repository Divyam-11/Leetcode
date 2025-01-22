class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        vector<int> rows = {0, 0, 1, -1};
        vector<int> columns = {1, -1, 0, 0};
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j] == 1)
                    q.push({i, j});
                else
                    result[i][j] = -1;
            }
        }
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int row = x + rows[i];
                int col = y + columns[i];
                int height = result[x][y];
                if (row < 0 || col < 0 || row >= m || col >= n || isWater[row][col] == 1 || result[row][col] != -1)
                    continue;

                result[row][col] = height + 1;
                q.push({row, col});
            }
        }
        return result;
    }
};