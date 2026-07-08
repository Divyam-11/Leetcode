class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> prefCnt(n + 1, 0);
        vector<int> digits;

        for (int i = 0; i < n; i++) {
            prefCnt[i + 1] = prefCnt[i];
            if (s[i] != '0') {
                prefCnt[i + 1]++;
                digits.push_back(s[i] - '0');
            }
        }

        int m = digits.size();

        vector<long long> pw(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pw[i] = (pw[i - 1] * 10) % MOD;

        vector<long long> prefVal(m + 1, 0);
        vector<long long> prefSum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefVal[i + 1] = (prefVal[i] * 10 + digits[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digits[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = prefCnt[l];
            int R = prefCnt[r + 1] - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x = (prefVal[R + 1] - prefVal[L] * pw[len]) % MOD;
            if (x < 0) x += MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};