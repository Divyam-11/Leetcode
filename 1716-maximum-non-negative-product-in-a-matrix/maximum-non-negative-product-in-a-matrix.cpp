class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        vector<vector<long long>> dp_min(
            grid.size(), vector<long long>(grid[0].size(), INT_MAX));
        vector<vector<long long>> dp_max(
            grid.size(), vector<long long>(grid[0].size(), INT_MIN));
        dp_max[0][0] = dp_min[0][0] = grid[0][0];
        for (int i = 0; i < grid.size(); i++) {

            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0 && j == 0)
                    continue;
                long long max_ans = LLONG_MIN;
                long long min_ans = LLONG_MAX;
                if (i != 0) {
                    long long ul = INT_MAX;
                    long long uh = INT_MIN;
                    ul = dp_min[i - 1][j];
                    uh = dp_max[i - 1][j];
                    max_ans =
                        max({ul * 1LL * grid[i][j], uh * 1LL * grid[i][j]});
                    min_ans =
                        min({ul * 1LL * grid[i][j], uh * 1LL * grid[i][j]});
                }
                if (j != 0) {
                    long long ll = INT_MAX;
                    long long lh = INT_MIN;
                    ll = dp_min[i][j - 1];
                    lh = dp_max[i][j - 1];
                    max_ans = max({max_ans, ll * 1LL * grid[i][j],
                                   lh * 1LL * grid[i][j]});
                    min_ans = min({min_ans, ll * 1LL * grid[i][j],
                                   lh * 1LL * grid[i][j]});
                }
                dp_min[i][j] = min_ans;
                dp_max[i][j] = max_ans;
            }
        }
        return dp_max.back().back() >= 0 ? dp_max.back().back() % 1000000007
                                        : -1;
    }
};