
class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited, int delRow[], int delCol[]) {
        visited[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, visited, delRow, delCol);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};
        int result = 0;

        // Perform DFS for boundary cells
        for (int i = 0; i < grid[0].size(); i++) {
            if (!visited[0][i] && grid[0][i] == 1) {
                dfs(0, i, grid, visited, delRow, delCol);
            }
            if (!visited[grid.size() - 1][i] && grid[grid.size() - 1][i] == 1) {
                dfs(grid.size() - 1, i, grid, visited, delRow, delCol);
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            if (!visited[i][0] && grid[i][0] == 1) {
                dfs(i, 0, grid, visited, delRow, delCol);
            }
            if (!visited[i][grid[0].size() - 1] && grid[i][grid[0].size() - 1] == 1) {
                dfs(i, grid[0].size() - 1, grid, visited, delRow, delCol);
            }
        }

        // Count the enclaves
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    result++;
                }
            }
        }

        return result;
    }
};