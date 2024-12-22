class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        vector<int> rows = {0, -1, 0, 1};
        vector<int> cols = {-1, 0, 1, 0};
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0,0}});
        distance[0][0] = 0;
        while (!pq.empty())
        {
            int effort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if (x == m - 1 && y == n - 1)
                return effort;
            for (int i = 0; i < 4; i++)
            {
                int temp_x = x + rows[i];
                int temp_y = y + cols[i];
                if (temp_x >= 0 && temp_y >= 0 && temp_x < m && temp_y < n)
                {
                    int temp_effort = max(abs(heights[x][y] - heights[temp_x][temp_y]),effort);
                    if (temp_effort < distance[temp_x][temp_y])
                    {
                        distance[temp_x][temp_y] = temp_effort;
                        pq.push({temp_effort, {temp_x, temp_y}});
                    }
                }
            }
        }
        return 0;
    }
};