class Solution
{
public:
    vector<int> rows = {0, -1, 0, 1};
    vector<int> cols = {-1, 0, 1, 0};
    bool solve(int i, int j, int index, string word, vector<vector<char>> &board, vector<vector<int>> &visited)
    {
        
        if (index == word.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j])
            return false;

        visited[i][j] = 1;
        if (word[index] == board[i][j])
            index++;
        else
            { visited[i][j] = 0;
                return false;}
        for (int k = 0; k < 4; k++)
        {
            int newRow = i + rows[k];
            int newCol = j + cols[k];
            if (solve(newRow, newCol, index, word, board, visited))
                return true;
        }

        visited[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size()));
        for(int i = 0 ;i < board.size();i++){
            for(int j = 0 ;j < board[0].size();j++){
                if(solve(i,j,0,word,board,visited)) return true;
            }
        }
        return false;
    }
};