class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        // If the starting or ending cell is blocked, return -1
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        vector<int> rows = {-1, 0, 1, 0, -1, -1, 1, 1};
        vector<int> cols = {0, -1, 0, 1, -1, 1, -1, 1};
        vector<vector<int>> distance(grid.size(), vector<int>(grid.size(), INT_MAX));
        queue<pair<int, int>> q;
        q.push({0, 0});
        distance[0][0] = 1;
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            if (temp.first == grid.size() - 1 && temp.second == grid[0].size() - 1)
            {
                return distance[grid.size() - 1][grid[0].size() - 1];
            }
            for (int i = 0; i < 8; i++)
            {

                int temp_row = temp.first + rows[i];
                int temp_col = temp.second + cols[i];
                if (temp_row >= 0 && temp_col >= 0 && temp_row < grid.size() && temp_col < grid[0].size() && grid[temp_row][temp_col] != 1 && 1 + distance[temp.first][temp.second] < distance[temp_row][temp_col])
                {
                    q.push({temp_row, temp_col});
                    distance[temp_row][temp_col] = 1 + distance[temp.first][temp.second];
                }
            }
        }
        return -1;
    }
};