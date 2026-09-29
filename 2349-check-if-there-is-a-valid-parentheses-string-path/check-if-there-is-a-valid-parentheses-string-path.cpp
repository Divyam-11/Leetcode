#include <vector>
#include <cstring>

class Solution {
private:
    char mem[101][101][101];
    int max_m, max_n;

    bool dfs(int i, int j, int k, const std::vector<std::vector<char>>& grid) {
        k += (grid[i][j] == '(') ? 1 : -1;

        if (k < 0) return false;

        int remaining_steps = (max_m - 1 - i) + (max_n - 1 - j);
        if (k > remaining_steps) return false;

        if (i == max_m - 1 && j == max_n - 1) {
            return k == 0;
        }

        if (mem[i][j][k] != 0) {
            return mem[i][j][k] == 1;
        }

        bool match = false;

        if (i + 1 < max_m) {
            match = match || dfs(i + 1, j, k, grid);
        }

        if (j + 1 < max_n) {
            match = match || dfs(i, j + 1, k, grid);
        }

        mem[i][j][k] = match ? 1 : 2;
        return match;
    }

public:
    bool hasValidPath(std::vector<std::vector<char>>& grid) {
        max_m = grid.size();
        max_n = grid[0].size();

        if ((max_m + max_n - 1) % 2 != 0) return false;

        if (grid[0][0] == ')' || grid[max_m - 1][max_n - 1] == '(') return false;

        std::memset(mem, 0, sizeof(mem));

        return dfs(0, 0, 0, grid);
    }
};