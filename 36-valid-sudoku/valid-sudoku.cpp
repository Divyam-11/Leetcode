class Solution
{
public:
    vector<vector<char>> answer;
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool col[9][9] = {false};
        bool row[9][9] = {false};
        bool box[9][9] = {false};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                int num = board[i][j] - '0' - 1;
                int ind = ((i / 3) * 3) + (j / 3);

                if (col[i][num] || row[j][num] || box[ind][num])
                {
                    return false;
                }
                col[i][num] = true;
                row[j][num] = true;
                box[ind][num] = true;
            }
        }
        return true;
    }
    int countNums(vector<vector<char>> &board)
    {
        int num_count = 0;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                    num_count++;
            }
        }
        return num_count;
    }
    void helper(vector<vector<char>> &board)
    {
        if (countNums(board) == 81)
        {
            answer = board;
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                for (int k = 1; k < 10; k++)
                {
                    if (board[i][j] != '.')
                        continue;
                    board[i][j] = k + '0';
                    if (isValidSudoku(board))
                    {
                        helper(board);
                    }
                    board[i][j] = '.';
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        helper(board);
        board = answer;
    }
};