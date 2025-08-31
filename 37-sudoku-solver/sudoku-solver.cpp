class Solution {
public:
    vector<vector<char>> ans;
    bool isValidSudoku(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;

            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == c) return false;
        }
        return true;
    }
    bool helper(vector<vector<char>> &board){
        for(int i =0 ;i < board.size();i++){
            for(int j =0 ; j < board.size();j++){
                if(board[i][j] == '.'){
                    
                    for(int k = 1;k<10;k++){
                        
                        if(isValidSudoku(board,i,j,k+'0')){
                            board[i][j] = k + '0';
                            if(helper(board)) return true;

                        }
                        board[i][j] = '.';

                    }
                    return false;
                }
               
            }

        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};