class Solution
{
public:
    vector<int> rows = {0, -1, 0, 1};
    vector<int> cols = {-1, 0, 1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({0, {i, j}});
                    visited[i][j] = 0;
                }
            }
        }
        while (!q.empty())
        {
            int dis = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newRow = x + rows[i];
                int newCol = y + cols[i];
                if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n || mat[newRow][newCol] == 0)
                {
                    continue;
                }
                if (visited[newRow][newCol] > dis + 1)
                {
                    visited[newRow][newCol] = dis + 1;
                    q.push({dis + 1, {newRow, newCol}});
                }
            }
        }
        return visited;
    }
};