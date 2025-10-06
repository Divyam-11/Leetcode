class Solution
{
public:
    vector<int> row = {0, -1, 0, 1};
    vector<int> columns = {-1, 0, 1, 0};

    int swimInWater(vector<vector<int>> &grid)
    {

        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> distance(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        pq.push({grid.back().back(), {grid.size() - 1, grid[0].size() - 1}});
        distance[n - 1][n - 1] = grid[n - 1][n - 1];
        while (!pq.empty())
        {
            int cost = pq.top().first;
            int a = pq.top().second.first;
            int b = pq.top().second.second;
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = a + row[i];
                int y = b + columns[i];
                if (x >= 0 && y >= 0 && x < n && y < n)
                {
                    int temp_distance = max(cost, grid[x][y]);
                    if (temp_distance < distance[x][y])
                    {
                        distance[x][y] = temp_distance;
                        pq.push({temp_distance, {x, y}});
                    }
                }
            }
        }
        return distance[0][0];
    }
};