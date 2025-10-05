class Solution {
public:
    vector<int> directions = {0, 1, 0, -1, 0};
    
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visit) {
        int ROWS = heights.size(), COLS = heights[0].size();
        visit[r][c] = true;
        for (int d = 0; d < 4; d++) {
            int nr = r + directions[d];
            int nc = c + directions[d+1];
            if (nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS 
                && !visit[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, visit);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));
        
        // DFS from Pacific
        for (int c = 0; c < COLS; c++) {
            dfs(0, c, heights, pac);
            dfs(ROWS-1, c, heights, atl);
        }
        for (int r = 0; r < ROWS; r++) {
            dfs(r, 0, heights, pac);
            dfs(r, COLS-1, heights, atl);
        }
        
        vector<vector<int>> result;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (pac[r][c] && atl[r][c])
                    result.push_back({r, c});
            }
        }
        return result;
    }
};
