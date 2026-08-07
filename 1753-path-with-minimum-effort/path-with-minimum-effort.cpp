class Solution
{
public:
    vector<int> rows = {-1, 0, 1, 0};
    vector<int> cols = {0, -1, 0, 1};

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        visited[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int newRow = x + rows[i];
                int newCol = y + cols[i];
                if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n)
                {
                    continue;
                }
                int newCost = max(cost,(int)abs(heights[x][y] - heights[newRow][newCol]));
                if (newCost < visited[newRow][newCol])
                {
                    visited[newRow][newCol] = newCost;
                    pq.push({newCost, {newRow, newCol}});
                }
            }
        }
        return visited.back().back();
    }
};