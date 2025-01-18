class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    { // 0 0 1 -1
        // 1 -1 0 0
        vector<int> rows = {0, 0, 1, -1};
        vector<int> columns = {1, -1, 0, 0};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> distance(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        distance[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            int weight = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int row = x + rows[i];
                int col = y + columns[i];
                if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
                    continue;

                int tempWeight = weight;
                if (grid[x][y] != i + 1)
                    tempWeight++;
                if (tempWeight < distance[row][col])
                {
                    distance[row][col] = tempWeight;
                    pq.push({tempWeight, {row, col}});
                }
            }
        }
        return distance[grid.size() - 1][grid[0].size() - 1];
    }
};