class Solution {
public:
    vector<vector<vector<int>>> dp;

    pair<int,int> getCoord(int pos) {
        return {pos / 6, pos % 6};
    }

    int getDist(int a, int b) {
        auto [x1, y1] = getCoord(a);
        auto [x2, y2] = getCoord(b);
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string &word, int i, int f1, int f2) {
        if (i == word.size()) return 0;

        if (dp[i][f1][f2] != -1)
            return dp[i][f1][f2];

        int curr = word[i] - 'A';

        int pickf1 = (f1 == 26 ? 0 : getDist(f1, curr)) 
                   + solve(word, i + 1, curr, f2);

        int pickf2 = (f2 == 26 ? 0 : getDist(f2, curr)) 
                   + solve(word, i + 1, f1, curr);

        return dp[i][f1][f2] = min(pickf1, pickf2);
    }

    int minimumDistance(string word) {
        int n = word.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(27, vector<int>(27, -1)));
        return solve(word, 0, 26, 26);
    }
};