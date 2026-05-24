class Solution {
public:
    int n;
    vector<int> dp;

    int f(vector<int>& a, int d, int i) {
        if (dp[i] != -1)
            return dp[i];

        int ans = 1;

        for (int j = i - 1; j >= max(0, i - d); j--) {
            if (a[j] >= a[i])
                break;
            ans = max(ans, 1 + f(a, d, j));
        }

        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            if (a[j] >= a[i])
                break;
            ans = max(ans, 1 + f(a, d, j));
        }

        return dp[i] = ans;
    }

    int maxJumps(vector<int>& a, int d) {
        n = a.size();
        dp.resize(n, -1);

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, f(a, d, i));
        }

        return ans;
    }
};