class Solution
{
public:
    vector<int> rows = {0, -1, 0, 1};
    vector<int> cols = {-1, 0, 1, 0};
    void dfs(int x, int y, vector<vector<char>> &board, int m, int n)
    {
        board[x][y] = '*';
        for (int i = 0; i < 4; i++)
        {
            int newRow = x + rows[i];
            int newCol = y + cols[i];
            if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n)
            {
                continue;
            }
            if (board[newRow][newCol] == 'O')
                dfs(newRow, newCol, board, m, n);
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
                dfs(0, i, board, m, n);
            if (board[m - 1][i] == 'O')
                dfs(m - 1, i, board, m, n);
        }
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
                dfs(i, 0, board, m, n);
            if (board[i][n - 1] == 'O')
                dfs(i, n - 1, board, m, n);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
    }
};