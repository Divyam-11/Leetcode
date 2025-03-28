class Solution
{
public:
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int points = 0;
        vector<int> Row = {0, -1, 0, 1};
        vector<int> Col = {-1, 0, 1, 0};
        vector<int> result(queries.size());
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        vector<pair<int, int>> queries_with_index(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            queries_with_index[i] = {queries[i], i};
        }
        sort(queries_with_index.begin(), queries_with_index.end());
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        for (int i = 0; i < queries.size(); i++)
        {
            cout << "i = " << i << endl;
            while (!pq.empty() && pq.top().first < queries_with_index[i].first)
            {
                int node = pq.top().first;
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                pq.pop();
                cout << "visiting" << x << "," << y << " value : " << node << " size : " << pq.size() << endl;
                points++;
                for (int i = 0; i < 4; i++)
                {
                    int maxRow = x + Row[i];
                    int maxCol = y + Col[i];
                    if (maxRow < 0 || maxRow >= grid.size() || maxCol < 0 || maxCol >= grid[0].size() || visited[maxRow][maxCol])
                        continue;
                        pq.push({grid[maxRow][maxCol], {maxRow, maxCol}});
                        visited[maxRow][maxCol] = 1;
                }
            }
            result[i] = points;
        }
        vector<int> ans(result.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int og_index = queries_with_index[i].second;
            ans[og_index] = result[i];
        }
        cout << points << endl;
        return ans;
    }
};