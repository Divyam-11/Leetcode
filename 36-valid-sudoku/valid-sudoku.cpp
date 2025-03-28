class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool col[9][9] = {false};
        bool row[9][9] = {false};
        bool box[9][9] = {false};

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.'){
                    continue;
                }
                int num = board[i][j] - '0' - 1;
                int ind = ((i / 3) * 3) + (j / 3);

                if (col[i][num] || row[j][num] || box[ind][num]){
                    return false;
                }
                col[i][num] = true;
                row[j][num] = true;
                box[ind][num] = true;
            }
        }
        return true;
    }
};