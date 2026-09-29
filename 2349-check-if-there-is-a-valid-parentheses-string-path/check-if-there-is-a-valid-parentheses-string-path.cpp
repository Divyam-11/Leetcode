class Solution
{
public:
    int dp[101][101][201];
    bool solve(int i, int j, vector<vector<char>> &grid, int open)
    {
        if(open < 0 )return false;
        if (i >= grid.size() || j >= grid[0].size())
            return false;
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
             if (grid[i][j] == '(')
                open++;
            else
                open--;
            if (open == 0)
                return true;
            else
                return false;
        }
        int oldOpen = open;
        if(dp[i][j][open] != -1) return dp[i][j][open];
        if (grid[i][j] == '(')
            open++;
        else
            open--;
        return dp[i][j][oldOpen] = solve(i + 1, j, grid, open) || solve(i, j + 1, grid, open);
    }
    bool hasValidPath(vector<vector<char>> &grid)
    {
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, grid, 0);
    }
};