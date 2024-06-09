class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> freq;

        // Check rows
        for (int i = 0; i < 9; i++) {
            freq.clear();
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (freq.find(board[i][j]) != freq.end()) {
                    return false;
                } else {
                    freq[board[i][j]]++;
                }
            }
        }

        // Check columns
        for (int j = 0; j < 9; j++) {
            freq.clear();
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                if (freq.find(board[i][j]) != freq.end()) {
                    return false;
                } else {
                    freq[board[i][j]]++;
                }
            }
        }

        // Check 3x3 subgrids using a 2D array of unordered_set
        unordered_set<char> subgrid_freq[3][3];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int subgrid_row = i / 3;
                int subgrid_col = j / 3;
                if (subgrid_freq[subgrid_row][subgrid_col].find(board[i][j]) != subgrid_freq[subgrid_row][subgrid_col].end()) {
                    return false;
                } else {
                    subgrid_freq[subgrid_row][subgrid_col].insert(board[i][j]);
                }
            }
        }

        return true;
    }
};