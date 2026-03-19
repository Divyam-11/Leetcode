class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size();

        vector<vector<int>> px(n+1, vector<int>(m+1, 0));
        vector<vector<int>> py(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                px[i][j] = px[i-1][j] + px[i][j-1] - px[i-1][j-1] + (g[i-1][j-1] == 'X');
                py[i][j] = py[i-1][j] + py[i][j-1] - py[i-1][j-1] + (g[i-1][j-1] == 'Y');
            }
        }

        int res = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (px[i][j] == py[i][j] && px[i][j] > 0) res++;
            }
        }

        return res;
    }
};