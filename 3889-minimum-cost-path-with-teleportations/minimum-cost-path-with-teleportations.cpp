class Solution
{
public:
    int minCost(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));

        vector<pair<int, int>> cells;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cells.push_back({i, j});
            }
        }

        sort(cells.begin(), cells.end(),
             [&](pair<int, int> a, pair<int, int> b)
             {
                 return grid[a.first][a.second] <
                        grid[b.first][b.second];
             });

        for (int i = 0; i <= k; i++)
        {

            int best = INT_MAX;

            for (int j = 0; j < (int)cells.size(); j++)
            {
                int r = cells[j].first;
                int c = cells[j].second;

                best = min(best, cost[r][c]);

                if (j + 1 < (int)cells.size() &&
                    grid[r][c] ==
                        grid[cells[j + 1].first][cells[j + 1].second])
                {
                    continue;
                }

                for (int k = j; k >= 0; k--)
                {
                    if (grid[cells[k].first][cells[k].second] != grid[r][c])
                        break;
                    cost[cells[k].first][cells[k].second] = best;
                }
            }

            for (int j = n - 1; j >= 0; j--)
            {
                for (int k = m - 1; k >= 0; k--)
                {

                    if (j == n - 1 && k == m - 1)
                    {
                        cost[j][k] = 0;
                        continue;
                    }

                    if (j + 1 < n)
                        cost[j][k] = min(cost[j][k],
                                         cost[j + 1][k] + grid[j + 1][k]);

                    if (k + 1 < m)
                        cost[j][k] = min(cost[j][k],
                                         cost[j][k + 1] + grid[j][k + 1]);
                }
            }
        }

        return cost[0][0];
    }
};