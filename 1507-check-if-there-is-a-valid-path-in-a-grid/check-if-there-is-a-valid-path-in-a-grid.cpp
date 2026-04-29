class Solution
{
public:
    vector<int> rows = {0, -1, 0, 1};
    vector<int> columns = {-1, 0, 1, 0};
    // LURD
    vector<vector<int>> mp = {{0, 2}, {1, 3}, {0, 3}, {2, 3}, {0, 1}, {1, 2}};
    vector<set<int>> hehe = {{1, 4, 6}, {2, 3, 4}, {1, 3, 5}, {2, 5, 6}};
    bool hasValidPath(vector<vector<int>> &grid)
    {
        
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size()));
        queue<pair<int, int>> q;
        q.push({0, 0});

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            if(i == grid.size()-1 && grid[0].size()-1 == j) return true;
            visited[i][j] = 1;
            q.pop();
            int val = grid[i][j];

            for (auto idx : mp[val - 1])
            {
                int new_Row = i + rows[idx];
                int new_col = j + columns[idx];
                if (new_Row < 0 || new_Row >= grid.size() || new_col < 0 || new_col >= grid[0].size() || visited[new_Row][new_col])
                {
                    continue;
                }
                if (hehe[idx].find(grid[new_Row][new_col]) != hehe[idx].end())
                {
                    q.push({new_Row, new_col});
                    if (new_Row == grid.size() - 1 && new_col == grid[0].size() - 1)
                        return true;
                }
            }
        }
        return false;
    }
};