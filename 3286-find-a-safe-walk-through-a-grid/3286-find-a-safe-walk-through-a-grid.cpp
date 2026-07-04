class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size();
        int n = grid[0].size();
        int row[] = {0, -1, 0, 1};
        int col[] = {-1, 0, 1, 0};
        priority_queue<pair<int, pair<int, int>>> q; // {health,{x,y}};
        vector<vector<int>> distance(m, vector<int>(n, 0));
        if (grid[0][0] == 1)
            health--;
        q.push({health, {0, 0}});
        while (!q.empty())
        {

            int hp = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;

            if (x == m - 1 && y == n - 1)
                return true;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newX = x + row[i];
                int newY = y + col[i];
                if (newX < 0 || newY < 0 || newY >= n || newX >= m)
                    continue;
                int newHp = hp - grid[newX][newY];
                if (newHp > distance[newX][newY])
                {
                    distance[newX][newY] = newHp;
                    q.push({newHp, {newX, newY}});
                }
            }
        }
        return distance[m-1][n-1];
    }
};