class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        int initialHealth = health - grid[0][0];
        if (initialHealth <= 0)
            return false;

        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = initialHealth;

        queue<tuple<int, int, int>> q;
        q.push({0, 0, initialHealth});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c, h] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newHealth = h - grid[nr][nc];

                    if (newHealth > 0 && newHealth > visited[nr][nc]) {
                        visited[nr][nc] = newHealth;
                        q.push({nr, nc, newHealth});
                    }
                }
            }
        }

        return false;
    }
};